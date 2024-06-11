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
			//��������к�
			if (j == 0)
			{
				if (i + 1 < 10)
				{
					cout << " ";
				}
				cout << i + 1;
			}
			//�����������
			switch (board[i][j])
			{
			case 0:
				if (i == 0)
				{
					if (j == 0)
					{
						cout << "��";
					}
					else if (j == 14)
					{
						cout << "��";
					}
					else
					{
						cout << "��";
					}
				}
				else if (i == 14)
				{
					if (j == 0)
					{
						cout << "��";
					}
					else if (j == 14)
					{
						cout << "��";
					}
					else
					{
						cout << "��";
					}
				}
				else
				{
					if (j == 0)
					{
						cout << "��";
					}
					else if (j == 14)
					{
						cout << "��";
					}
					else
					{
						cout << "��";
					}
				}
				break;
			case 1:
				cout << "��";
				break;
			case 2:
				cout << "��";
				break;

			}
			cout << " ";
		}
		//��ĩ����
		cout << endl;
	}
	cout << "  A B C D E F G H I J K L M N O" << endl;

}
void simpleUI()
{
	bool exit = false;                                                      //   ͼ�λ����棬û��
	int color = 1;                                                          //   ͼ�λ����棬û��
	int board[15][15] = { 0 };												//   ͼ�λ����棬û��
	AIWine* ai = new AIWine();               //  aiwine  ����Ĵ��������캯��
	//system("pause");

	ai->setSize(15);                                                        //  ���̶̹�12*12������set��0��11��
	do
	{
		cout << "��������������(��h8):" << endl;                            //   ͼ�λ����棬û��
		string inputStr("");	                                            //   ͼ�λ����棬û��
		cin >> inputStr;	                                                //   ͼ�λ����棬û��
		int x, y;	                                                  	    //   ͼ�λ����棬û��
		if (inputStr.length() == 2)	                                        //   ͼ�λ����棬û��
		{	                                                                //   ͼ�λ����棬û��
			x = inputStr[0] - 'a'; 	                                        //   ͼ�λ����棬û��
			y = inputStr[1] - '1';	                                        //   ͼ�λ����棬û��
		}	                                                                //   ͼ�λ����棬û��
		else if (inputStr.length() == 3)	                                //   ͼ�λ����棬û��
		{	                                                                //   ͼ�λ����棬û��
			x = inputStr[0] - 'a';	                                        //   ͼ�λ����棬û��
			y = (inputStr[1] - '0') * 10 + inputStr[2] - '1';	            //   ͼ�λ����棬û��
		}	                                                                //   ͼ�λ����棬û��
		ai->turnMove(x, y);                  //  �Է�ai����󣬵��ã�x�����ŵģ�y�Ǻ��ŵ�
		board[y][x] = color;	                                            //   ͼ�λ����棬û��
		color = 3 - color;	                                                //   ͼ�λ����棬û��
		drawBoard(board);                                                   //   ͼ�λ����棬û��
		// ai ˼����һ��
		int nextX, nextY;     				 //  �Է�ai����󣬵���
		ai->turnBest(nextX, nextY);			 //  �Է�ai����󣬵���
		board[nextY][nextX] = color;                                        //   ͼ�λ����棬û��
		color = 3 - color;                                                  //   ͼ�λ����棬û��
		drawBoard(board);                                                   //   ͼ�λ����棬û��
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
			printf("��ǰ����ռ���ڴ��СΪ��%d KB\n", pmc.WorkingSetSize / 1024);            //   204680kb��Լ200mb��Ӧ�ò��ᳬ��350mb��ֻҪʱ�䲻���Ϳ���
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