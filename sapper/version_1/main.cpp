#include <iostream>
#include <stdlib.h>
using namespace std;
#define s 6

void FillArr(int arr[][s], int i)
{
	for (; i > 0; i--)
	{
		arr[rand() % s][rand() %s] = -1;
	}
}

bool check(int i, int j) 
{
	if (i ==-1 || j == -1||i==s||j==s) 
	{
		return 0;
	}
	else 
	{
		return 1;
	}
}

void FillNumb(int arr[][s])
{
	int n=0;
	for (int i = 0; i < s; i++) 
	{
		for (int j = 0; j < s; j++) 
		{
			if(arr[i][j]==-1){ }
			else 
			{
				for (int i1 = i - 1; i1 <= i + 1; i1++)
				{
					for (int j1 = j - 1; j1 <= j + 1; j1++)
					{
						if (check(i1, j1))
						{
							if (arr[i1][j1] == -1)
							{
								n++;
							}
						}
					}
				}
				arr[i][j] = n;
				n = 0;
			}
			
			
		}
	}
}

void disp(int arr[][s], bool arrv[][s]) {
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			if (arrv[i][j] == 1) {
				cout << arr[i][j]<<" ";
			}
			else {
				cout << "." << " ";
			}
		}
		cout << endl;
	}
}
void op(int arr[][s], bool arrv[][s], int x, int y) 
{
	if (arr[x][y] == 0) {
		arrv[x][y] = 1;
		if (check(x + 1, y)) {
			if (arr[x + 1][y] != -1 && arrv[x + 1][y] == 0) {
				op(arr, arrv, x + 1, y);
			}
		}
		if (check(x - 1, y)) {
			if (arr[x - 1][y] != -1 && arrv[x - 1][y] == 0) {
				op(arr, arrv, x - 1, y);
			}
		}
		if (check(x, y - 1)) {
			if (arr[x][y - 1] != -1 && arrv[x][y - 1] == 0) {
				op(arr, arrv, x, y - 1);
			}
		}
		if (check(x, y + 1)) {
			if (arr[x][y + 1] != -1 && arrv[x][y + 1] == 0) {
				op(arr, arrv, x, y + 1);
			}
		}
		if (check(x + 1, y+1)) {
			if (arr[x + 1][y+1] != -1 && arrv[x + 1][y+1] == 0) {
				op(arr, arrv, x + 1, y+1);
			}
		}
		if (check(x + 1, y-1)) {
			if (arr[x + 1][y-1] != -1 && arrv[x + 1][y-1] == 0) {
				op(arr, arrv, x + 1, y-1);
			}
		}
		if (check(x - 1, y-1)) {
			if (arr[x - 1][y-1] != -1 && arrv[x - 1][y-1] == 0) {
				op(arr, arrv, x - 1, y-1);
			}
		}
		if (check(x - 1, y+1)) {
			if (arr[x - 1][y+1] != -1 && arrv[x - 1][y+1] == 0) {
				op(arr, arrv, x - 1, y+1);
			}
		}
		if (arrv[x][y] == 1) return;
	}
	else if (arr[x][y] != 0) {
		arrv[x][y] = 1;
		if (check(x + 1, y)) {
			if (arr[x + 1][y] != -1 && arr[x + 1][y] == 0 && arrv[x + 1][y] == 0) {
				op(arr, arrv, x + 1, y);
			}
		}
		if (check(x - 1, y)) {
			if (arr[x - 1][y] != -1&& arr[x - 1][y] ==0 && arrv[x - 1][y] == 0) {
				op(arr, arrv, x - 1, y);
			}
		}
		if (check(x, y - 1)) {
			if (arr[x][y - 1] != -1&& arr[x][y - 1] ==0 && arrv[x][y - 1] == 0) {
				op(arr, arrv, x, y - 1);
			}
		}
		if (check(x, y + 1)) {
			if (arr[x][y + 1] != -1&& arr[x][y + 1] ==0 && arrv[x][y + 1] == 0) {
				op(arr, arrv, x, y + 1);
			}
		}
		if (check(x+1, y + 1)) {
			if (arr[x+1][y + 1] != -1 && arr[x+1][y + 1] == 0 && arrv[x+1][y + 1] == 0) {
				op(arr, arrv, x+1, y + 1);
			}
		}
		if (check(x-1, y + 1)) {
			if (arr[x-1][y + 1] != -1 && arr[x-1][y + 1] == 0 && arrv[x-1][y + 1] == 0) {
				op(arr, arrv, x-1, y + 1);
			}
		}
		if (check(x + 1, y - 1)) {
			if (arr[x + 1][y - 1] != -1 && arr[x + 1][y - 1] == 0 && arrv[x + 1][y - 1] == 0) {
				op(arr, arrv, x + 1, y - 1);
			}
		}
		if (check(x - 1, y - 1)) {
			if (arr[x - 1][y - 1] != -1 && arr[x - 1][y - 1] == 0 && arrv[x - 1][y - 1] == 0) {
				op(arr, arrv, x - 1, y - 1);
			}
		}
		if (arrv[x][y] == 1) return;
	}
}

int num1(int arr[][s]) {
	int n = 0;
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			if (arr[i][j] == -1) {
				n++;
			}
		}
	}
	return n;
}

int num2(bool arr[][s]) {
	int n = 0;
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			if (arr[i][j] == 1) {
				n++;
			}
		}
	}
	return n;
}

int main() 
{
	bool arrv[s][s] = { 0 };
	int arr[s][s]={0};
	FillArr(arr, 7);
	FillNumb(arr);
	int x, y;
	while (1) 
	{
		disp(arr, arrv);
		if (num1(arr) + num2(arrv) == s * s) 
		{
			cout << "YOU WON" << endl;
			return 0;
		}
		cin >> x;
		cin >> y;
		x--;
		y--;
		if (arr[x][y] == -1)
		{
			for (int i = 0; i < s; i++)
			{
				for (int j = 0; j < s; j++)
				{
					cout << arr[i][j] << " ";
				}
				cout << endl;
			}
			return 0;
			
		}
		else if(arr[x][y]==0)
		{
			op(arr, arrv, x, y);
		}
		else {
			arrv[x][y] = 1;
		}
	}
}
