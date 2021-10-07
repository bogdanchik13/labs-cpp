#include <conio.h>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <ctime>

int processArray(int* inArr, size_t n, int a, int b)
{
	printf("Массив вещественных чисел\n");
	for (size_t i = 0; i < n; ++i)           //домножение на число из диапазона
	{
		if (i % 2 == 0)
		{
			inArr[i] = rand() % ((b - a + 1) + a); //  ((b - a + 1) + a) - определние границ rand
		}
		else
		{
			inArr[i] = 1;
		}
		printf("%d %s", inArr[i], " ");
	}

	int cnt = 0;
	for (size_t i = 0; i < n; ++i)           //Счетчик кол-ва двузн. чисел
	{
		if ((inArr[i] / 100 == 0) && (inArr[i] / 10 != 0))
			cnt++;
	}
	printf("\nМассив двузначных чисел\n");
	int* outArr = new int[cnt];              // массив двузн. чисел
	for (size_t i = 0; i < n; ++i)
	{
		if ((inArr[i] / 100 == 0) && (inArr[i] / 10 != 0)) // условие четного индекса
		{
			for (int j = 0; j < cnt; ++j) // вывод на экран
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
	
	for (size_t i = 0; i < size; ++i) // инициализация массива единицами
		inputArr[i] = 1;

	srand(time(NULL));

	
	int a, b;
	// ввод a и b (диапазона)
	printf("Введите a и b  (a < 0)\n");
	printf("a = ");
	scanf_s("%d", &a);
	printf("b = ");
	scanf_s("%d", &b);

	int cnt = processArray(inputArr, size, a, b);
	printf("%s %d", "\nДвузначных чисел: ", cnt);

	
	return 0;
}
