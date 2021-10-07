#define _CRT_SECURE_NO_WARNINGS

#include <conio.h>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

char* stringCopy(char* dest, const char* src, size_t num)
{
	for (size_t i = 0; i < num; ++i)
		dest[i] = src[i];

	return dest;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	char src[] = "Work hard to get what you like, otherwise you'll be forced to just like what you get.";
	int num;
	cin >> num;
	char dest1[100];
	char dest2[100];

	printf("%s", src);
	dest1[num] = '\0';
	strncpy(dest1, src, num);
	
	printf("%s %s", "\nstrncpy:", dest1);

	stringCopy(dest2, src, num);
	dest2[num] = '\0';
	printf("%s %s %s", "\nstringCopy:", dest2, "\n");

	
	return 0;
}
