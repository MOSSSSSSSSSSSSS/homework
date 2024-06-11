// 2253209 –≈07 ¡ıº—≈Û
#include<iostream>
using namespace std;

int main()
{
	int i, j, light[100] = {0};
	for (i = 1; i <= 100; i++)
	{
		for (j = 0; j < 100; j++)
		{
			if ((j + 1) % i == 0)
			{
				if (light[j] == 0)
				{
					light[j] = 1;
				}
				else
				{
					light[j] = 0;
				}
			}
		}
	}
	for (i = 0; i < 100; i++)
	{
		if (light[i] == 1)
		{
			if (i + 1 == 100)
			{
				cout << i + 1;
			}
			else
			{
				cout << i + 1 << ' ';
			}
		}
	}
	cout << endl;

	return 0;
}