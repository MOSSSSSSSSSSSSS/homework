
#include<iostream>
#include<cstdlib>
#include<sstream>
#include<string>
#include "AI.h"
using namespace std;


AI wine;

//小写字母转换成大写
void toupper(string& str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		char& c = str[i];
		if (c >= 'a' && c <= 'z')
		{
			c += 'A' - 'a';
		}
	}
}
/*--------------------------------*/
//控制台的简单界面
void simpleUI();
char board[15][15] = { 0 };
char chessType = 1;
char chessCount = 0;
bool isEnd = false;
void drawBoard()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			//行首输出行号
			if (j == 0)
			{
				if (i + 1 < 10)
				{
					cout << " ";
				}
				cout << i + 1;
			}
			//输出棋盘内容
			switch (board[i][j])
			{
			case 0:
				if (i == 0)
				{
					if (j == 0)
					{
						cout << "┌";
					}
					else if (j == 14)
					{
						cout << "┐";
					}
					else
					{
						cout << "┬";
					}
				}
				else if (i == 14)
				{
					if (j == 0)
					{
						cout << "└";
					}
					else if (j == 14)
					{
						cout << "┘";
					}
					else
					{
						cout << "┴";
					}
				}
				else
				{
					if (j == 0)
					{
						cout << "├";
					}
					else if (j == 14)
					{
						cout << "┤";
					}
					else
					{
						cout << "┼";
					}
				}
				break;
			case 1:
				cout << "●";
				break;
			case 2:
				cout << "○";
				break;

			}
		}
		//行末换行
		cout << endl;
	}
	cout << "  A B C D E F G H I J K L M N O" << endl;
}
void checkWin()
{
	if (wine.CheckWin())
	{
		if (chessType == 3)
		{
			cout << "你赢了！！！" << endl;
		}
		else
		{
			cout << "电脑赢了！！！" << endl;
		}
		cout << "输入1重新开始游戏，其它任意键退出程序" << endl;
		int num = 0;
		cin >> num;
		if (num == 1)
		{
			memset(board, 0, sizeof(board));
			chessCount = 0;
			chessType = 1;
			wine.ReStart();
			drawBoard();
		}
		else
		{
			isEnd = true;
		}
	}
}
//往控制台棋盘添加棋子
void addChess(char x, char y)
{
	board[y][x] = chessType;
	chessType = 3 - chessType;
	chessCount++;
	drawBoard();
}

//控制台交互界面
void simpleUI()
{
	wine.SetSize(15);
	string input_pos = "";

	Pos result = { 0,0 };
	Pos input = { 0,0 };
	drawBoard();
	do
	{
		if (chessType == 1)
		{
			cout << "请输入下棋坐标(如h8):" << endl;
			cin >> input_pos;
			if (input_pos.length() == 2)
			{
				input.x = input_pos[0] - 'a';
				input.y = input_pos[1] - '1';
			}
			else if (input_pos.length() == 3)
			{
				input.x = input_pos[0] - 'a';
				input.y = (input_pos[1] - '0') * 10 + input_pos[2] - '1';
			}
			addChess(input.x, input.y);
		}
		else
		{
			wine.PutChess(input);
			result = wine.GetBestMove();
			wine.PutChess(result);
			addChess(result.x, result.y);
		}
		checkWin();
	} while (!isEnd);
	exit(0);
}
int gomocup()
{
	string command;
	Pos input, best;
	char dot;
	int size = 15;
	wine.SetSize(15);
	while (1)
	{
		cin >> command;
		toupper(command);

		if (command == "START")
		{
			cin >> size;
			if (size > MaxSize || size <= 5)
			{
				cout << "ERROR" << endl;
			}
			else
			{
				wine.SetSize(size);
				cout << "OK" << endl;
			}
		}
		else if (command == "RESTART")
		{
			wine.ReStart();
			cout << "OK" << endl;
		}
		else if (command == "TAKEBACK")
		{
			wine.DelMove();
			cout << "OK" << endl;
		}
		else if (command == "BEGIN")
		{
			best = wine.GetBestMove();
			wine.PutChess(best);
			cout << best.x << "," << best.y << endl;
		}
		else if (command == "TURN")
		{
			cin >> input.x >> dot >> input.y;
			if (input.x < 0 || input.x >= size || input.y < 0 || input.y >= size
				|| wine.cell[input.x + 4][input.y + 4].piece != Empty)
			{
				cout << "ERROR" << endl;
			}
			else
			{
				wine.PutChess(input);
				best = wine.GetBestMove();
				wine.PutChess(best);
				cout << best.x << "," << best.y << endl;
			}
		}
		else if (command == "BOARD")
		{
			int c;
			Pos m;
			stringstream ss;
			wine.ReStart();

			cin >> command;
			toupper(command);
			while (command != "DONE")
			{
				ss.clear();
				ss << command;
				ss >> m.x >> dot >> m.y >> dot >> c;
				if (m.x < 0 || m.x >= size || m.y < 0 || m.y >= size
					|| wine.cell[m.x + 4][m.y + 4].piece != Empty)
				{
					cout << "ERROR" << endl;
				}
				else
				{
					wine.PutChess(m);
				}
				cin >> command;
				toupper(command);
			}
			best = wine.GetBestMove();
			wine.PutChess(best);
			cout << best.x << "," << best.y << endl;
		}
		else if (command == "INFO")
		{
			int value;
			string key;
			cin >> key;
			toupper(key);

			if (key == "TIMEOUT_TURN")
			{
				cin >> value;
				if (value != 0)
					wine.timeout_turn = value;

			}
			else if (key == "TIMEOUT_MATCH")
			{
				cin >> value;
				if (value != 0)
					wine.timeout_match = value;

			}
			else if (key == "TIME_LEFT")
			{
				cin >> value;
				if (value != 0)
					wine.time_left = value;

			}
			else if (key == "MAX_MEMORY")
			{
				cin >> value;
				// TODO
			}
			else if (key == "GAME_TYPE")
			{
				cin >> value;
				// TODO
			}
			else if (key == "RULE")
			{
				cin >> value;
				// TODO
			}
			else if (key == "FOLDER")
			{
				string t;
				cin >> t;
			}
		}
		else if (command == "PLAY")
		{
			simpleUI();
		}
		else if (command == "END")
		{
			exit(0);
		}
	}
}
int main()
{
	gomocup();
}