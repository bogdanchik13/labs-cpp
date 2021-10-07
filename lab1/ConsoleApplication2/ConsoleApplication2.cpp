#include <conio.h>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>

#define PI 3.14159265

using std::cout;
using std::endl;
using std::setw;


void initializeArr(float* arr, size_t size) // инициализация массива
{
	for (size_t i = 0; i < size; ++i)
		arr[i] = (float)(i * exp((PI * i) / 100)); // ф-ла из условия задачи x[n] = n ∙ exp(πn/100)
}
void printArr1D(float* arr, size_t size)
{
	cout << "Одномерный массив" << endl;
	for (size_t i = 0; i < size; ++i)
		cout << *(arr + i) << " ";
	cout << endl;
}
float** Array2D(float* arr1D, size_t n)
{
	float** arr2D = new float* [n];
	for (size_t i = 0; i < n; ++i)
		*(arr2D + i) = new float[n];

	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < n; ++j)
			*(*(arr2D + i) + j) = *(arr1D + i * n + j);
	}

	float tmp;                    // реализация "первый элемент - сумма трех следующих"
	for (size_t i = 0; i < n; ++i)
	{
		*(*(arr2D + i) + 0) = 0;
		tmp = *(*(arr2D + i) + 0);
		for (size_t j = 0; j < n; ++j)
			tmp += *(*(arr2D + i) + j);
		*(*(arr2D + i) + 0) = tmp;
	}
	return arr2D;
}

void printArr2D(float** arr, size_t n)
{
	cout << "Двумерный массив" << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << setw(10) << *(*(arr + i) + j);
		cout << endl;
	}
}

void delArr1D(float* arr)
{
	delete[] arr;
}
void delArr2D(float** arr, size_t n)
{
	for (size_t i = 0; i < n; ++i)
		delete[] arr[i];

	delete[] arr;
}


int main()
{
	setlocale(LC_ALL, "Russian");

	const size_t size = 16;
	const size_t N = 4;

	float* inputArr = new float[size];
	initializeArr(inputArr, size); 

	float** outputArr = Array2D(inputArr, N);

	printArr1D(inputArr, size);
	printArr2D(outputArr, N);

	delArr1D(inputArr); // очистка
	delArr2D(outputArr, N); // очистка

	
	return 0;
}

