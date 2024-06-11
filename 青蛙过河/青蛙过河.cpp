#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%d", (m + 1) * 1 << n);
}