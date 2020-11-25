// Lab_7_3_2.cpp
// <Ратушна Соломія >
// Лабораторна робота № 7.3.2
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, int rowcount, int colcount, const int Low, const int High, int i, int j);
int k(int** a, int rowcount, int colcount, int f, int i, int j);
void PrintRow(int** a, const int rowNo, const int N, int colNo);
void PrintRows(int** a, const int N, int rowNo, int rowcount);
void max(int** a, int rowcount, int colcount, const int Low, const int High, int i, int j, int c);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -8;
	int High = 14;
	int rowcount, colcount;
	cout << "rowcount = "; cin >> rowcount;
	cout << "colcount = "; cin >> colcount;
	int** a = new int* [rowcount];
	for (int i = 0; i < rowcount; i++) a[i] = new int[colcount];
	Create(a, rowcount, colcount, Low, High, 0, 0);
	PrintRows(a, colcount, 0, rowcount);
	cout << "rows without 0 = " << k(a, rowcount, colcount, 0, 0, 0);
	max(a, rowcount, colcount, Low, High, 0, 0, 0);
	return 0;
}
void Create(int** a, int rowcount, int colcount, const int Low, const int High, int i, int j)
{
	if (i < rowcount)
	{
		if (j < colcount)
		{
			a[i][j] = Low + rand() % (High - Low + 1);
			Create(a, rowcount, colcount, Low, High, i, j + 1);
		}
		Create(a, rowcount, colcount, Low, High, i + 1, j);
	}
}
void PrintRow(int** a, const int rowNo, const int rowcount, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < rowcount - 1)PrintRow(a, rowNo, rowcount, colNo + 1);
	else cout << endl;
}
void PrintRows(int** a, const int colcount, int rowNo, int rowcount)
{
	PrintRow(a, rowNo, rowcount, 0);
	if (rowNo < colcount - 1)PrintRows(a, colcount, rowNo + 1, rowcount);
	else cout << endl;
}
int k(int** a, int rowcount, int colcount, int f, int i, int j)
{
	int d = 0;
	if (i < rowcount)
	{
		if (j < colcount)
		{
			if (a[i][j] != 0) { k(a, rowcount, colcount, f + 1, i, j + 1); }
		}
		if (f == colcount) { d++; }
		f = 0;
		k(a, rowcount, colcount, f, i + 1, j);
	}
	return d;
}
void max(int** a, int rowcount, int colcount, const int Low, const int High, int i, int j, int c)
{
	if (i < rowcount)
	{
		if (j < colcount)
		{
			if (a[i][j] == High) { max(a, rowcount, colcount, Low, High, i, j + 1, c + 1); }
		}
		max(a, rowcount, colcount, Low, High, i + 1, j, c);
	}
	cout << endl << "count of max elements in the matrix = " << c;
}
