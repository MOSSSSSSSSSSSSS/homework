#include "AIWine.h"
#include "ChessShape.h"
#include <assert.h>
#include<iostream>
#include<string>
#include<sstream>
#include <windows.h>
#include <psapi.h>
#include <stdio.h>
#include<bitset>
using namespace std;
void simpleUI();
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
void gomocup()
{
	AIWine* ai = new AIWine();
	string command;
	char dot;
	int size;
	bool isEnded = false;
	bool isSimpleUi = false;
	while (1)
	{
		cin >> command;
		toupper(command);

		if (command == "START")
		{
			cin >> size;
			if (ai->setSize(size))
			{
				cout << "OK" << endl;
			}
			else
			{
				cout << "ERROR" << endl;
			}
		}
		else if (command == "RESTART")
		{
			ai->restart();
			cout << "OK" << endl;
		}
		else if (command == "TAKEBACK")
		{
			ai->turnUndo();
			cout << "OK" << endl;
		}
		else if (command == "BEGIN")
		{
			int x, y;
			ai->turnBest(x, y);
			cout << x << "," << y << endl;
		}
		else if (command == "TURN")
		{
			int x, y;
			cin >> x >> dot >> y;
			if (ai->isValidPos(x, y))
			{
				ai->turnMove(x, y);
				ai->turnBest(x, y);
				cout << "MESSAGE " << "node:" << ai->nSearched / 1000 << "k eval:" << ai->rootBest.value << endl;
				cout << x << "," << y << endl;
			}
			else
			{
				cout << "ERROR" << endl;
			}
		}
		else if (command == "BOARD")
		{
			int x, y, c;
			stringstream ss;
			ai->restart();

			cin >> command;
			toupper(command);
			while (command != "DONE")
			{
				ss.clear();
				ss << command;
				ss >> x >> dot >> y >> dot >> c;
				if (ai->isValidPos(x, y))
				{
					ai->turnMove(x, y);
				}
				else
				{
					cout << "ERROR" << endl;
				}
				cin >> command;
				toupper(command);
			}
			if (c == 2)
			{
				ai->turnBest(x, y);
				cout << "MESSAGE " << "node:" << ai->nSearched << " eval:" << ai->rootBest.value << endl;
				cout << x << "," << y << endl;
			}
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
				if (value != 0) ai->timeout_turn = value;
			}
			else if (key == "TIMEOUT_MATCH")
			{
				cin >> value;
				if (value != 0) ai->timeout_match = value;
			}
			else if (key == "TIME_LEFT")
			{
				cin >> value;
				if (value != 0) ai->time_left = value;
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
		else if (command == "ABOUT")
		{
			cout << "name = \"Wine\", version =\"2.1\", author = \"JinJieWang\", country = \"China\"" << endl;
		}
		else if (command == "END")
		{
			isEnded = true;
			break;
		}
		else if (command == "SIMPLE_UI") {
			isSimpleUi = true;
			break;
		}
	}
	delete ai;
	if (isEnded) {
		exit(0);
	}
	else if (isSimpleUi) {
		simpleUI();
	}
}
void drawBoard(int board[15][15])
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
			cout << " ";
		}
		//行末换行
		cout << endl;
	}
	cout << "  A B C D E F G H I J K L M N O" << endl;

}
void simpleUI()
{
	bool exit = false;                                                      //   图形化界面，没用
	int color = 1;                                                          //   图形化界面，没用
	int board[15][15] = { 0 };												//   图形化界面，没用
	AIWine* ai = new AIWine();               //  aiwine  对象的创建，构造函数
	//system("pause");

	ai->setSize(15);                                                        //  棋盘固定12*12，不用set（0到11）
	do
	{
		cout << "请输入下棋坐标(如h8):" << endl;                            //   图形化界面，没用
		string inputStr("");	                                            //   图形化界面，没用
		cin >> inputStr;	                                                //   图形化界面，没用
		int x, y;	                                                  	    //   图形化界面，没用
		if (inputStr.length() == 2)	                                        //   图形化界面，没用
		{	                                                                //   图形化界面，没用
			x = inputStr[0] - 'a'; 	                                        //   图形化界面，没用
			y = inputStr[1] - '1';	                                        //   图形化界面，没用
		}	                                                                //   图形化界面，没用
		else if (inputStr.length() == 3)	                                //   图形化界面，没用
		{	                                                                //   图形化界面，没用
			x = inputStr[0] - 'a';	                                        //   图形化界面，没用
			y = (inputStr[1] - '0') * 10 + inputStr[2] - '1';	            //   图形化界面，没用
		}	                                                                //   图形化界面，没用
		ai->turnMove(x, y);                  //  对方ai下棋后，调用，x是竖着的，y是横着的
		board[y][x] = color;	                                            //   图形化界面，没用
		color = 3 - color;	                                                //   图形化界面，没用
		drawBoard(board);                                                   //   图形化界面，没用
		// ai 思考下一步
		int nextX, nextY;     				 //  对方ai下棋后，调用
		ai->turnBest(nextX, nextY);			 //  对方ai下棋后，调用
		board[nextY][nextX] = color;                                        //   图形化界面，没用
		color = 3 - color;                                                  //   图形化界面，没用
		drawBoard(board);                                                   //   图形化界面，没用
		for (int i = 0; i < ai->board->chessCount; i++)
		{
			Chess* c = ai->board->remChess[i];
			char p = c->piece;
			assert(p == BLACK || p == WHITE);
			for (int k = 0; k < 4; k++)
			{
				cout << "shape: " << int(c->shape[k][p])/* << ' ' << int(c->shape[k][1 - p])*/ << endl;
				cout << ai->board->chessCount << ' ' << "%%% k = " << k << ' ' << "p= " << int(p) << ' ' << char(ai->board->pointX(ai->board->remPoint[i]) - 4 + 'a') << ' ' << ai->board->pointY(ai->board->remPoint[i]) - 3 << ' ' << bitset<8>(c->pattern[k][p]) << ' ' << bitset<8>(c->pattern[k][1 - p]) << endl;
			}
		}
		PROCESS_MEMORY_COUNTERS pmc;
		if (GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc)))
		{
			printf("当前进程占用内存大小为：%d KB\n", pmc.WorkingSetSize / 1024);            //   204680kb，约200mb，应该不会超过350mb，只要时间不超就可以
		}
	} while (!exit);
	delete ai;
}
int main()
{
	//gomocup();
	simpleUI();
	return 0;
}