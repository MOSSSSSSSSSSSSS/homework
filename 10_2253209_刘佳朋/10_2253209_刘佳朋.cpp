#include<iostream>
#include<ctime>
#include<time.h>
#include<climits>

// ��������ʱ��
clock_t start_time, end_time;

// ���ݷ�Χ
int N;

// ��¼�Ƚϴ���
long long int cnt = 0;

// �õ�һ��[ minNum��maxNum ]�����֣������������������֤��׳��
int getint(const int minNum = INT_MIN, const int maxNum = INT_MAX, const std::string errorTips = "")
{
	int retNum = INT_MIN;
	while (1)
	{
		std::cin >> retNum;
		if (std::cin.fail() || retNum < minNum || retNum > maxNum) // ������������Ͳ�ͬ�����ֲ���Ҫ��Χ��
		{
			std::cin.clear();
			std::cin.ignore(1024, '\n');                           // ���������
			std::cout << errorTips;                                // ���������������ʾ
			continue;
		}
		break;
	}
	return retNum;
}


// ð������
void BubbleSort(int a[], int begin, int end)
{
	// i��¼��ǰ�����λ��
	for (int i = end; i >= begin; i--)
	{
		// j��¼��ǰ�Ƚ�Ԫ��
		for (int j = begin; j < i; j++)
		{	// ð��
			if (a[j] > a[j + 1])
			{
				std::swap(a[j], a[j + 1]);
			}
			cnt++;
		}
	}
}

// ѡ������
void SelectSort(int a[], int begin, int end)
{
	for (int i = begin; i < end; i++)
	{
		// temp��¼Ҫ������λ��
		int temp = i;
		for (int j = i + 1; j <= end; j++)
		{
			// ���½���λ�õļ�¼
			if (a[j] < a[temp]) temp = j;
			cnt++;
		}
		// ����
		std::swap(a[i], a[temp]);
	}
}

// ��������
void InsertSort(int a[], int begin, int end)
{
	for (int i = begin + 1; i <= end; i++)
	{
		for (int j = i; j > begin; j--)
		{
			// ����������ǰ�Ƚ�
			if (a[j] < a[j - 1]) std::swap(a[j], a[j - 1]);
			cnt++;
		}
	}
}

// ϣ������
void ShellSort(int a[], int begin, int end)
{
	// gapΪ�ֿ��С����ʼΪ���ݷ�Χ��1/2
	int gap = (end - begin + 1) / 2;
	while (gap)
	{
		for (int k = 0; k < gap; k++)
		{
			for (int i = begin + gap + k; i <= end; i += gap)
			{
				for (int j = i; j > begin + k; j -= gap)
				{
					if (a[j] < a[j - gap]) std::swap(a[j], a[j - gap]);
					cnt++;
				}
			}
		}
		// ��Сgap
		gap /= 2;
	}
}

// ��������
void QuickSort(int a[], int begin, int end)
{
	if (begin > end) return;
	// �Ƚ�ָ��
	int i = begin, j = end;

	while (i != j)
	{
		// a[begin]����Ϊ�Ƚϻ�׼
		while (a[j] >= a[begin] && j > i) j--;
		while (a[i] <= a[begin] && j > i) i++;
		if (j > i)	std::swap(a[i], a[j]);
		cnt += 3;
	}

	// ����ָ������λ�úͻ�׼λ��
	std::swap(a[i], a[begin]);

	// ��ָ������λ��Ϊ���֣���Ϊ���������µݹ�
	QuickSort(a, begin, i - 1);
	QuickSort(a, i + 1, end);
}


// �������������
void HeapAdjust(int a[], int begin, int i, int length)
{
	// ȡ����ǰԪ��i���ݴ�tmp
	int tmp = a[begin + i];

	// ��i�������ӽ�㿪ʼ,��2i+1����ʼ
	for (int k = 2 * i + 1; k < length; k = k * 2 + 1)
	{
		// ������ӽ��С�����ӽ�㣬��kָ�����ӽ��(2k+1��ʾ���ӽ�㣬2k+2��ʾ���ӽ��)
		if (k + 1 < length && a[begin + k] < a[begin + k + 1])  k++;

		cnt++;

		// ����ӽڵ���ڸ��ڵ�,���ӽڵ�ֵ�������ڵ�(���ý��н���)
		if (a[begin + k] > tmp)
		{
			cnt++;
			a[begin + i] = a[begin + k];
			i = k;// iָ��k,������Сֵ���ڽϴ�ֵ�·�
		}
		// ���¶��Ͻ��е���,��֤�·�������Ϊ�󶥶�
		else break;
	}
	//��forѭ�������󣬽���iΪ�������������ֵ���ھֲ��Ѷ�
	a[begin + i] = tmp;
}
// ������
void HeapSort(int a[], int begin, int end)
{
	// ����
	int length = end - begin + 1;
	// �����һ���ж��ӽڵ��λ��(length/2-1)��ʼ��������ϵ
	for (int i = length / 2 - 1; i >= 0; i--)
		HeapAdjust(a, begin, i, length);

	// ������Ѷ������һ��Ԫ�ص���λ��
	for (int j = length - 1; j > 0; j--)
	{
		std::swap(a[begin], a[begin + j]);// ���Ѷ�Ԫ����ĩβԪ�ؽ��н���
		HeapAdjust(a, begin, 0, j);  // �̶�β��λ�ã����¶Զѽ��е���
	}
}


// �鲢����
void MergeSort(int a[], int begin, int end)
{
	if (begin == end) return;
	// �ҵ��е�λ��
	int mid = (begin + end) / 2;

	// ��Ϊ���������µݹ�����
	MergeSort(a, begin, mid);
	MergeSort(a, mid + 1, end);

	// ����ָ��
	int i = begin, j = mid + 1, k = begin;

	// temp������ʱ�洢��ǰ���ֵ�Ԫ��
	int* temp = new int[100001];

	// ֻҪ�����ֶ�û���ߵ���β
	while (i <= mid && j <= end)
	{
		// �������ֵ�ǰָ��λ��ѡ���СԪ�ؼ���temp
		if (a[i] <= a[j]) temp[k++] = a[i++];
		else temp[k++] = a[j++];

		cnt++;
	}

	// ��δѡ���Ԫ�ؼ���temp
	while (i <= mid) temp[k++] = a[i++];
	while (j <= end) temp[k++] = a[j++];

	// �������temp����Ϣ���ݸ�a
	for (int i = begin; i <= end; i++) a[i] = temp[i];

	delete[]temp;
}


// ���������Ӻ���
void _RadixSort(int a[], int begin, int end, int exp)
{
	int* result = new int[100001];    //���Ͱ���ռ����ݺ����ʱ����

	int bucket[10] = { 0 };    //��ʼ��10��Ͱ

	// ����A�������ݳ��ֵĴ����洢��Ͱbucket��
	for (int i = begin; i <= end; i++)
	{
		bucket[(a[i] / exp) % 10]++;
		cnt++;
	}

	// ����bucket��Ԫ�ص�ֵ���������ֵ����A��Ԫ����result�е�λ��
	for (int i = 1; i < 10; i++)
		bucket[i] = bucket[i] + bucket[i - 1];

	// ��a�е�Ԫ����䵽result�У��Ӻ���ǰ�ţ���������
	for (int i = end; i >= begin; i--)
	{
		int iexp = (a[i] / exp) % 10;
		result[bucket[iexp] - 1] = a[i];
		bucket[iexp]--;
		cnt++;
	}
	// ������õ�����result���ƻ�A��
	for (int i = begin; i <= end; i++)
	{
		a[i] = result[i - begin];
		cnt++;
	}

	delete[]result;
}
// ��������
void RadixSort(int a[], int begin, int end)
{
	// ��ȡ�����е����ֵ
	int infoMax = 0;
	for (int i = begin; i <= end; i++) infoMax = infoMax > a[i] ? infoMax : a[i];

	// �Ӹ�λ��ʼ��������a��λ���л�������
	for (int iexp = 1; infoMax / iexp > 0; iexp *= 10)
		_RadixSort(a, begin, end, iexp);
}


int main()
{
	srand((unsigned int)(time(0)));

	std::cout << "**        �����㷨        **" << std::endl;
	std::cout << "============================" << std::endl;
	std::cout << "**       1.ð������       **" << std::endl;
	std::cout << "**       2.ѡ������       **" << std::endl;
	std::cout << "**       3.��������       **" << std::endl;
	std::cout << "**       4.ϣ������       **" << std::endl;
	std::cout << "**       5.��������       **" << std::endl;
	std::cout << "**       6.������         **" << std::endl;
	std::cout << "**       7.�鲢����       **" << std::endl;
	std::cout << "**       8.��������       **" << std::endl;
	std::cout << "============================" << std::endl;

	std::cout << std::endl << "���������������ĸ���(1-10000)��";
	N = getint(1, 10000, "����������������룺");

	int a[10001];


	// ���������
	for (int i = 0; i < N; i++)
		a[i] = rand();
	// ��¼��ʼʱ��
	start_time = clock();
	BubbleSort(a, 0, N - 1);
	// ��¼����ʱ��
	end_time = clock();
	std::cout << "The run time is: " << double(end_time - start_time) / CLOCKS_PER_SEC << "s" << std::endl;
	std::cout << "ð������Ƚϴ���: " << cnt << std::endl << std::endl;
	cnt = 0;


	// ���������
	for (int i = 0; i < N; i++)
		a[i] = rand();
	// ��¼��ʼʱ��
	start_time = clock();
	SelectSort(a, 0, N - 1);
	// ��¼����ʱ��
	end_time = clock();
	std::cout << "The run time is: " << double(end_time - start_time) / CLOCKS_PER_SEC << "s" << std::endl;
	std::cout << "ѡ������Ƚϴ���: " << cnt << std::endl << std::endl;
	cnt = 0;


	// ���������
	for (int i = 0; i < N; i++)
		a[i] = rand();
	// ��¼��ʼʱ��
	start_time = clock();
	InsertSort(a, 0, N - 1);
	// ��¼����ʱ��
	end_time = clock();
	std::cout << "The run time is: " << double(end_time - start_time) / CLOCKS_PER_SEC << "s" << std::endl;
	std::cout << "��������Ƚϴ���: " << cnt << std::endl << std::endl;
	cnt = 0;


	// ���������
	for (int i = 0; i < N; i++)
		a[i] = rand();
	// ��¼��ʼʱ��
	start_time = clock();
	ShellSort(a, 0, N - 1);
	// ��¼����ʱ��
	end_time = clock();
	std::cout << "The run time is: " << double(end_time - start_time) / CLOCKS_PER_SEC << "s" << std::endl;
	std::cout << "ϣ������Ƚϴ���: " << cnt << std::endl << std::endl;
	cnt = 0;


	// ���������
	for (int i = 0; i < N; i++)
		a[i] = rand();
	// ��¼��ʼʱ��
	start_time = clock();
	QuickSort(a, 0, N - 1);
	// ��¼����ʱ��
	end_time = clock();
	std::cout << "The run time is: " << double(end_time - start_time) / CLOCKS_PER_SEC << "s" << std::endl;
	std::cout << "��������Ƚϴ���: " << cnt << std::endl << std::endl;
	cnt = 0;


	// ���������
	for (int i = 0; i < N; i++)
		a[i] = rand();
	// ��¼��ʼʱ��
	start_time = clock();
	HeapSort(a, 0, N - 1);
	// ��¼����ʱ��
	end_time = clock();
	std::cout << "The run time is: " << double(end_time - start_time) / CLOCKS_PER_SEC << "s" << std::endl;
	std::cout << "������Ƚϴ���: " << cnt << std::endl << std::endl;
	cnt = 0;


	// ���������
	for (int i = 0; i < N; i++)
		a[i] = rand();
	// ��¼��ʼʱ��
	start_time = clock();
	MergeSort(a, 0, N - 1);
	// ��¼����ʱ��
	end_time = clock();
	std::cout << "The run time is: " << double(end_time - start_time) / CLOCKS_PER_SEC << "s" << std::endl;
	std::cout << "�鲢����Ƚϴ���: " << cnt << std::endl << std::endl;
	cnt = 0;


	// ���������
	for (int i = 0; i < N; i++)
		a[i] = rand();
	// ��¼��ʼʱ��
	start_time = clock();
	RadixSort(a, 0, N - 1);
	// ��¼����ʱ��
	end_time = clock();
	std::cout << "The run time is: " << double(end_time - start_time) / CLOCKS_PER_SEC << "s" << std::endl;
	std::cout << "��������Ƚϴ���: " << cnt << std::endl << std::endl;
	cnt = 0;


	system("pause");
	return 0;
}

