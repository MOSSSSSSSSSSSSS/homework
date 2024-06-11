#include<iostream>
using namespace std;

void bubble_sort(int arr[],int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void select_sort(int arr[],int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int k = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[k] > arr[j])
			{
				k = j;
			}
		}
		int temp = arr[k];
		arr[k] = arr[i];
		arr[i] = temp;
	}
}
void insert_sort(int arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
			{
				int temp = arr[i];
				for (int k = i; k > j; k--)
				{
					arr[k] = arr[k - 1];
				}
				arr[j] = temp;
				break;
			}
		}
	}
}
int binary_seach(int arr[],int size,int p)
{
	int left = 0;
	int right = size - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] == p)
		{
			return mid;
		}
		else if (arr[mid] > p)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	return -1;
}
int lowerbound(int arr[],int size,int p)
{
	int left = 0, right = size - 1, lastpos = -1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] >= p)
		{
			right = mid - 1;
		}
		else
		{
			lastpos = mid;
			left = mid + 1;
		}
	}

	return lastpos;
}
void merge(int a[],int s,int m,int e,int b[])
{
	int pb=0;
	int p1 = s, p2 = m + 1;
	while (p1 <= m && p2 <= e)
	{
		if (a[p1] < a[p2])
		{
			b[pb++] = a[p1++];
		}
		else
		{
			b[pb++] = a[p2++];
		}
	}
	if (p1 <= m)
	{
		while (p1 <= m)
		{
			b[pb++] = a[p1++];
		}
	}
	else
	{
		while (p2 <= e)
		{
			b[pb++] = a[p2++];
		}
	}
	for (int i = 0; i < e - s + 1; i++)
	{
		a[s + i] = b[i];
	}
}
void mergesort(int a[],int s,int e,int b[])
{
	if (s < e)
	{
		int m = s + (e - s) / 2;
		mergesort(a, s, m, b);
		mergesort(a, m + 1, e, b);
		merge(a, s, m, e, b);
	}
}
void swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}
void quicksort(int a[],int s,int e)
{
	if (s >= e)
	{
		;
	}
	else
	{
		int k = a[s];
		int i = s, j = e;
		while (i != j)
		{
			while (i < j && a[j] >= k)
			{
				j--;
			}
			swap(a[i], a[j]);
			while (j > i && a[i] <= k)
			{
				i++;
			}
			swap(a[i], a[j]);
		}
		quicksort(a, s, i - 1);
		quicksort(a, i+ 1, e);
	}
}

int main()
{
	int arr[20] = { 4,48,54,22,21,6,30,3,0,55,58,54,666,1145,0,-8,-99,430,1,2 };
	int b[20];
	int size = sizeof(arr) / sizeof(int);
	quicksort(arr,0,size-1);
	for (int i = 0; i < 20; i++)
	{
		cout << arr[i] << ' ';
	}
}