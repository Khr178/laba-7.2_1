// Lab_7_2_1.cpp
// < Копейки Христини >
// Лабораторна робота № 7.2.1)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 8

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
bool SearchMaxEven(int** a, const int k, const int n, int& minEven);
bool SearchMinEven(int** a, const int k, const int n, int& minEven);

int main()
{
	srand((unsigned)time(NULL));
	int Low = -12;
	int High = 37;
	int k,n;
	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;

	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[k];
	int** a2 = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];

	Create(a, k, n, Low, High);
	Print(a, k, n);

	int minEven;
	if (SearchMinEven(a, k, n, minEven))
		cout << "min even = " << minEven << endl;
	else
		cout << "there are no even elements" << endl;
	int maxEven;
	if (SearchMaxEven(a, k, n, maxEven))
		cout << "max even = " << maxEven << endl;
	else
		cout << "there are no even elements" << endl;

	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;
	return 0;

	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void Create(int** a, const int k, const int n, const int Low, const int High)
{
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
	
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int k, const int n)
{
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;

	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
bool SearchMaxEven(int** a, const int k, const int n, int& minEven)
{
	return false;
}
bool SearchMinEven(int** a, const int k, const int n, int& minEven)
{
	return false;
}
bool SearchMinEven(int** a, const int n, int& minEven)
{
	int j, k = -1;
	for (int i = 0; i < n; i++)
	{
		j = n - 1 - i;
		if (a[i][j] % 2 == 0)
		{
			k = i;
			minEven = a[i][j];
			break;
		}
	}

	if (k == -1)
		return false;
	for (int i = k + 1; i < n; i++)
	{
		j = n - 1 - i;
		if (a[i][j] % 2 == 0 && a[i][j] < minEven)
		{
			minEven = a[i][j];
		}
	}
	return true;
}
bool SearchMaxEven(int** a, const int n, int& maxEven)
{
	int j, k = -1;
	for (int i = 0; i < n; i++)
	{
		j = k - 1 - i;
		if (a[i][j] % 2 == 0)
		{
			k = i;
			maxEven = a[i][j];
			break;
		}
	}

	if (k == -1)
		return false;
	for (int i = k + 1; i < n; i++)
	{
		j = n - 1 - i;
		if (a[i][j] % 2 == 0 && a[i][j] < maxEven)
		{
			maxEven = a[i][j];
		}
	}
	return true;
}








