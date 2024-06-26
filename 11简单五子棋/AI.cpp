
#include "AI.h"
#include<ctime>
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;

// 返回当前已用的搜索时间
int AI::GetTime()
{
	return (double)(clock() - start) / CLOCKS_PER_SEC * 1000;
}
// 返回每步可用的搜索时间
int AI::StopTime()
{
	return (timeout_turn < time_left / 7) ? timeout_turn : time_left / 7;
}

// 查询置换表
int AI::ProbeHash(int depth, int alpha, int beta)
{
	Hashe* phashe = &hashTable[zobristKey & (hashSize - 1)];
	if (phashe->key == zobristKey)
	{
		if (phashe->depth >= depth)
		{
			if (phashe->hashf == hash_exact)
			{
				return phashe->val;
			}
			else if (phashe->hashf == hash_alpha && phashe->val <= alpha)
			{
				return phashe->val;
			}
			else if (phashe->hashf == hash_beta && phashe->val >= beta)
			{
				return phashe->val;
			}
		}
	}
	return unknown;
}

// 写入置换表
void AI::RecordHash(int depth, int val, int hashf)
{
	Hashe* phashe = &hashTable[zobristKey & (hashSize - 1)];
	phashe->key = zobristKey;
	phashe->val = val;
	phashe->hashf = hashf;
	phashe->depth = depth;
}

//界面落子
void AI::PutChess(Pos next)
{
	next.x += 4, next.y += 4;
	MakeMove(next);
}

// 返回最佳点
Pos AI::GetBestMove()
{
	Pos best = MainSearch();
	best.x -= 4, best.y -= 4;
	// 输出思考信息
	cout << "MESSAGE" << " depth=" << searchDepth << " NPS=" << total / (ThinkTime + 1) << "k" << endl;
	cout << "MESSAGE" << " best: [" << best.x << "," << best.y << "]" << " val=" << bestPoint.val << endl;
	cout << "MESSAGE" << " bestLine:";
	for (int i = 0; i < bestLine.n; i++)
	{
		cout << " [" << bestLine.moves[i].x - 4 << "," << bestLine.moves[i].y - 4 << "]";
	}
	cout << endl;

	return best;
}

// 搜索最佳点
Pos AI::MainSearch()
{
	start = clock();
	total = 0;
	hashCount = 0;

	Pos bestMove;
	// 第一步下中心点
	if (step == 0)
	{
		bestMove.x = size / 2 + 4;
		bestMove.y = size / 2 + 4;
		return bestMove;
	}
	/* 第二步随机选择第一手棋周围一格内的点, 第三步随机选择第一手棋周围两格内的点 */
	if (step == 1 || step == 2)
	{
		int rx, ry;
		srand(time(NULL));
		do
		{
			//rand() % (step * 2 + 1) - step表示随机选择 -step 到 step 的值
			rx = remMove[0].x + rand() % (step * 2 + 1) - step;
			ry = remMove[0].y + rand() % (step * 2 + 1) - step;
		} while (!CheckXy(rx, ry) || cell[rx][ry].piece != Empty);
		bestMove.x = rx;
		bestMove.y = ry;
		return bestMove;
	}
	// 迭代加深搜索
	stopThink = false;
	bestPoint.val = 0;
	ply = 0;
	memset(IsLose, false, sizeof(IsLose));
	for (int i = MinDepth; i <= MaxDepth && !stopThink; i += 2)
	{
		searchDepth = i;
		bestPoint = RootSearch(searchDepth, -10001, 10000, &bestLine);
		if (stopThink || (searchDepth >= 10 && GetTime() >= 1000 && GetTime() * 12 > StopTime()))
		{
			break;
		}
	}

	ThinkTime = GetTime();
	bestMove = bestPoint.p;
	//cout << (double)hashCount / (total + 1) * 100 << endl;

	return bestMove;
}
// 根节点搜索
Point AI::RootSearch(int depth, int alpha, int beta, Line* pline)
{
	Point best = rootMove[0];
	Line line;

	if (depth == MinDepth)
	{
		Pos moves[64];
		rootCount = GenerateMove(moves);
		// 只存在一个可行着法，直接返回
		if (rootCount == 1)
		{
			stopThink = true;
			best.p = moves[0];
			best.val = 0;
			pline->n = 0;
			return best;
		}

		for (int i = 0; i < rootCount; i++)
		{
			rootMove[i].p = moves[i];
		}
	}
	else
	{
		for (int i = 1; i < rootCount; i++)
		{
			if (rootMove[i].val > rootMove[0].val)
			{
				Point temp = rootMove[0];
				rootMove[0] = rootMove[i];
				rootMove[i] = temp;
			}
		}
	}

	// 遍历可选点
	int val;
	for (int i = 0; i < rootCount; i++)
	{
		// 搜索非必败点
		Pos p = rootMove[i].p;
		if (!IsLose[p.x][p.y])
		{
			line.n = 0;
			MakeMove(p);
			do
			{
				if (i > 0 && alpha + 1 < beta)
				{
					val = -AlphaBeta(depth - 1, -alpha - 1, -alpha, &line);
					if (val <= alpha || val >= beta)
					{
						break;
					}
				}
				val = -AlphaBeta(depth - 1, -beta, -alpha, &line);
			} while (0);
			DelMove();

			rootMove[i].val = val;

			if (stopThink) break;

			if (val == -10000) IsLose[p.x][p.y] = true;


			if (val > alpha)
			{
				alpha = val;
				best.p = p;
				best.val = val;
				//保存最佳路线
				pline->moves[0] = p;
				memcpy(pline->moves + 1, line.moves, line.n * sizeof(Pos));
				pline->n = line.n + 1;
				//找到必胜
				if (val == 10000)
				{
					stopThink = true;
					return best;
				}
			}
		}
	}


	return best;
}
// 获取下一步着法
Pos AI::GetNextMove(MoveList& moveList)
{
	/*phase0:置换表着法
	 *phase1:生成全部着法
	 *phase2:依次返回phase1中的着法
	 */

	switch (moveList.phase)
	{
	case 0:
		moveList.phase = 1;
		Pv* e;
		e = &pvsTable[zobristKey % pvsSize];
		if (e->key == zobristKey)
		{
			moveList.hashMove = e->best;
			return e->best;
		}
	case 1:
		moveList.phase = 2;
		moveList.n = GenerateMove(moveList.moves);
		moveList.index = 0;
		if (moveList.first == false)
		{
			for (int i = 0; i < moveList.n; i++)
			{
				if (moveList.moves[i].x == moveList.hashMove.x && moveList.moves[i].y == moveList.hashMove.y)
				{
					for (int j = i + 1; j < moveList.n; j++)
					{
						moveList.moves[j - 1] = moveList.moves[j];
					}
					moveList.n--;
					break;
				}
			}
		}
	case 2:
		if (moveList.index < moveList.n)
		{
			moveList.index++;
			return moveList.moves[moveList.index - 1];
		}
	default:
		Pos p = { -1, -1 };
		return p;

	}
}
// 记录pv着法
void AI::RecordPVS(Pos best)
{
	Pv* e = &pvsTable[zobristKey % pvsSize];
	e->key = zobristKey;
	e->best = best;
}

//带pvs的搜索
int AI::AlphaBeta(int depth, int alpha, int beta, Line* pline)
{
	total++;

	static int cnt = 1000;
	if (--cnt <= 0)
	{
		cnt = 1000;
		if (GetTime() + 50 >= StopTime())
		{
			stopThink = true;
			return alpha;
		}
	}
	//对方已成五
	if (CheckWin())
	{
		return -10000;
	}
	// 叶节点
	if (depth <= 0)
	{
		return evaluate();
	}

	// 查询哈希表
	int val = ProbeHash(depth, alpha, beta);
	if (val != unknown)
	{
		hashCount++;
		return val;
	}

	Line line;
	MoveList moveList;
	moveList.phase = 0;
	moveList.first = true;
	Pos p = GetNextMove(moveList);
	Point best = { p, -10000 };
	int hashf = hash_alpha;
	while (p.x != -1)
	{
		//清空之前兄弟节点的路线
		line.n = 0;
		MakeMove(p);
		do
		{
			if (!moveList.first && alpha + 1 < beta)
			{
				val = -AlphaBeta(depth - 1, -alpha - 1, -alpha, &line);
				if (val <= alpha || val >= beta)
				{
					break;
				}
			}
			val = -AlphaBeta(depth - 1, -beta, -alpha, &line);
		} while (0);
		DelMove();

		if (stopThink) return best.val;

		if (val >= beta)
		{
			RecordHash(depth, val, hash_beta);
			RecordPVS(p);
			return val;
		}
		if (val > best.val)
		{
			best.val = val;
			best.p = p;
			if (val > alpha)
			{
				hashf = hash_exact;
				alpha = val;
				pline->moves[0] = p;
				memcpy(pline->moves + 1, line.moves, line.n * sizeof(Pos));
				pline->n = line.n + 1;
			}
		}
		p = GetNextMove(moveList);
		moveList.first = false;
	}


	RecordHash(depth, best.val, hashf);
	RecordPVS(best.p);

	return best.val;
}

// 棋型剪枝
int AI::CutMoveList(Pos* move, Point* cand, int candCount)
{
	//存在活四以上的棋形，直接返回
	if (cand[0].val >= 2400)
	{
		move[0] = cand[0].p;
		return 1;
	}
	int moveCount = 0;
	//对方已经活三了
	if (cand[0].val == 1200)
	{
		//找对方下一步能活四的点
		for (int i = 0; i < candCount; i++)
		{
			if (cand[i].val == 1200)
			{
				move[moveCount] = cand[i].p;
				moveCount++;
			}
			else break;
		}
		//找双方下一步能冲四的点
		for (int i = moveCount; i < candCount; ++i)
		{
			Cell* p = &cell[cand[i].p.x][cand[i].p.y];
			if (IsType(p, who, block4) || IsType(p, opp, block4))
			{
				move[moveCount] = cand[i].p;
				moveCount++;
				if (moveCount >= MaxMoves)
				{
					break;
				}
			}
		}
	}
	return moveCount;
}

// 生成着法
int AI::GenerateMove(Pos* move)
{
	int candCount = 0;                //待选着法数
	int moveCount = 0;                //筛选排序后的着法数
	int val;
	for (int i = b_start; i < b_end; i++)
	{
		for (int j = b_start; j < b_end; j++)
		{
			if (cell[i][j].IsCand && cell[i][j].piece == Empty)
			{
				val = EvaluateMove(&cell[i][j]);
				if (val > 0)
				{
					cand[candCount].p.x = i;
					cand[candCount].p.y = j;
					cand[candCount].val = val;
					++candCount;
				}
			}
		}
	}
	// 按价值排序
	sort(cand, candCount);
	//尝试剪枝，无法剪枝返回0，否则返回剪枝后的数量，并把剪枝后的走法存在move数组里
	moveCount = CutMoveList(move, cand, candCount);
	//如果没有剪枝，复制前MaxMoves个走法
	if (moveCount == 0)
	{
		for (int i = 0; i < candCount; i++)
		{
			move[i] = cand[i].p;
			moveCount++;
			if (moveCount >= MaxMoves)
			{
				break;
			}
		}
	}

	return moveCount;
}

// 插入排序
void AI::sort(Point* a, int n)
{
	int i, j;
	Point key;
	for (i = 1; i < n; i++)
	{
		key = a[i];
		for (j = i; j > 0 && a[j - 1].val < key.val; j--)
		{
			a[j] = a[j - 1];
		}
		a[j] = key;
	}
}
// 局面估值
int AI::evaluate()
{
	int whoType[8] = { 0 };               //记录下子方棋形数
	int oppType[8] = { 0 };               //记录另一方棋形数
	int block4_temp = 0;				//缓存上次循环己方的冲四数量，用于判断活四

	// 统计双方在空位能成的棋形，只统计两格以内的空位
	for (int i = b_start; i < b_end; ++i)
	{
		for (int j = b_start; j < b_end; ++j)
		{
			if (cell[i][j].IsCand && cell[i][j].piece == Empty)
			{
				block4_temp = whoType[block4];
				TypeCount(&cell[i][j], who, whoType);
				TypeCount(&cell[i][j], opp, oppType);
				//同一个点有两个冲四，那就相当于活四
				if (whoType[block4] - block4_temp >= 2)
				{
					whoType[block4] -= 2;
					whoType[flex4]++;
				}
			}
		}
	}

	// 当前局面轮到己方下棋
	// 1.己方存在连五点，必胜
	// 2.对方存在两个连五点，无法阻挡，必败
	// 3.对方不能成五，己方存在活四点，必胜
	if (whoType[win] >= 1) return 10000;
	if (oppType[win] >= 2) return -10000;
	if (oppType[win] == 0 && whoType[flex4] >= 1) return 10000;

	// 没有分出胜负，就计算评价值
	int whoScore = 0, oppScore = 0;
	for (int i = 1; i < 8; ++i)
	{
		whoScore += whoType[i] * eval[i];
		oppScore += oppType[i] * eval[i];
	}
	//因为轮到己方下，所以己方棋型更有威力，所以乘以1.2
	return whoScore * 1.2 - oppScore;
}
// 着法打分
int AI::EvaluateMove(Cell* c)
{
	int score[2];
	score[who] = pval[c->pattern[who][0]][c->pattern[who][1]][c->pattern[who][2]][c->pattern[who][3]];
	score[opp] = pval[c->pattern[opp][0]][c->pattern[opp][1]][c->pattern[opp][2]][c->pattern[opp][3]];


	/*200表示有双活三以上棋形，此时只返回其中更高的一方分值
	*否则返回双方分值之和
	*/
	if (score[who] >= 200 || score[opp] >= 200)
	{
		return score[who] >= score[opp] ? score[who] * 2 : score[opp];
	}
	else
	{
		return score[who] * 2 + score[opp];
	}
}