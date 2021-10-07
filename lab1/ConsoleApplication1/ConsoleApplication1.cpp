#include <conio.h>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <ctime>

int processArray(int* inArr, size_t n, int a, int b)
{
	printf("������ ������������ �����\n");
	for (size_t i = 0; i < n; ++i)           //���������� �� ����� �� ���������
	{
		if (i % 2 == 0)
		{
			inArr[i] = rand() % ((b - a + 1) + a); //  ((b - a + 1) + a) - ���������� ������ rand
		}
		else
		{
			inArr[i] = 1;
		}
		printf("%d %s", inArr[i], " ");
	}

	int cnt = 0;
	for (size_t i = 0; i < n; ++i)           //������� ���-�� �����. �����
	{
		if ((inArr[i] / 100 == 0) && (inArr[i] / 10 != 0))
			cnt++;
	}
	printf("\n������ ���������� �����\n");
	int* outArr = new int[cnt];              // ������ �����. �����
	for (size_t i = 0; i < n; ++i)
	{
		if ((inArr[i] / 100 == 0) && (inArr[i] / 10 != 0)) // ������� ������� �������
		{
			for (int j = 0; j < cnt; ++j) // ����� �� �����
			{
				outArr[j] = inArr[i];
				printf("%d %s", outArr[j], " ");
				break;
			}
		}
	}
	delete[] outArr;
	return cnt;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	const size_t size = 15;

	int inputArr[size];
	
	for (size_t i = 0; i < size; ++i) // ������������� ������� ���������
		inputArr[i] = 1;

	srand(time(NULL));

	
	int a, b;
	// ���� a � b (���������)
	printf("������� a � b  (a < 0)\n");
	printf("a = ");
	scanf_s("%d", &a);
	printf("b = ");
	scanf_s("%d", &b);

	int cnt = processArray(inputArr, size, a, b);
	printf("%s %d", "\n���������� �����: ", cnt);

	
	return 0;
}
