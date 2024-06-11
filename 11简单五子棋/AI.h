#pragma once
﻿
#ifndef  _AI
#define   _AI
#include "Board.h"
#include <ctime>
class AI :public Board
{
private:
	// 局面评价分值
	int eval[8] = { 0, 2, 12, 18, 96, 144, 800, 1200 };
	//int eval[8] = { 0, 2, 8, 10, 32, 40, 128, 140 };

public:
	int total = 0;					// 搜索局面数
	int hashCount = 0;				// hash表命中次数
	int searchDepth = 0;			// 实际搜索深度
	int time_left = 10000000;		//一局棋的剩余思考时间
	int timeout_turn = 5000;		//每步棋的思考时间
	int timeout_match = 10000000;	//一局棋的总思考时间
	int ThinkTime = 0;				//当前这步棋的思考时间
	Point bestPoint;				//AI思考的最佳点
	Line bestLine;					//AI思考的最佳路线
	clock_t start;					//AI开始思考的时间点
	bool stopThink = false;			//AI是否停止思考

	//搜索函数
	Pos MainSearch();
	//获取最佳走法
	Pos GetBestMove();
	void sort(Point* a, int n);
	void PutChess(Pos next);
	void RecordHash(int depth, int val, int hashf);
	void RecordPVS(Pos best);
	Pos GetNextMove(MoveList& moveList);
	int ProbeHash(int depth, int alpha, int beta);
	int GetTime();
	int StopTime();
	//评价走法
	int EvaluateMove(Cell* c);
	Point RootSearch(int depth, int alpha, int beta, Line* pline);
	int AlphaBeta(int depth, int alpha, int beta, Line* pline);
	//裁剪走法列表，成功返回裁剪后的数量，无法裁剪返回0
	int CutMoveList(Pos* move, Point* cand, int Csize);
	//生成可行走法
	int GenerateMove(Pos* move);
	//评价当前局面
	int evaluate();

};
#endif