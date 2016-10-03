// Console.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <windows.system.h>
#include <cstring>
using namespace std;
const char pic[2][17] = { {'+','-','-', '-', '-', '-', '-', '-', '+', '-','-', '-', '-', '-', '-', '-', '+' },{ ' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ' } };
int obj[9];
int num[9];
//1->●2->■3->▲4->◆
void pr(int n)
{
	int i, j;
	for (j = n; j < n+8; j++)
		cout << pic[0][j];
}
void pb(int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << "  "  ;
	return;
}
void pr2(int n)
{
	int i, j;
		for (j = n; j < n+4; j++)
			switch(obj[j])
				{
				case 0:
					cout << "  ";
					break;
				case 1:
					cout << "●";
					break;
				case 2:
					cout << "■";
					break;
				case 3:
					cout << "▲";
					break;
				case 4:
					cout << "◆";
					break;
				}
	return;
} 
//0->平1->左倾2->右倾
void p(int state)
{
	cout << "●=1N ■=2N ▲=3N ◆=4N" << endl;
	cout << "1 2 3 4   5 6 7 8" << endl;
	switch (state)
	{
	case 0:
		pr2(0);
		cout << "  ";
		pr2(4);
		cout<< endl;
		pr(0);
		cout << "+";
		pr(9);
		cout << endl;
		pb(4);
		cout << "|" << endl;
		break;
	case 1:
		pb(5);
		pr2(4);
		cout << endl;
		pb(5);
		pr(9);
		cout << endl;
		pr2(0);
		cout << "+" << endl;
		pr(0);
		cout << "|" << endl;
		break;
	case 2:
		pr2(0);
		cout << endl;
		pr(0);
		cout << endl;
		pb(4);
		cout << "+";
		pr2(4);
		cout << endl;
		pb(4);
		cout << "|";
		pr(9);
		cout << endl;
		break;
	default:
		break;
	}
	cout << "1.press [p] to place an object\n2.press [r] to remove an object\n3.press [q] to quit\n";
	return ;
}
int main()
{
	int i=0, j=0;
	//fill(&obj[0][0],&obj[3][8], 0);
	int inp2,inp3;
	char inp;
	int sta = 0,right=0,left=0;
	p(sta);
	cin >> inp;
	while (inp != 'q')
	{
		switch (inp)
		{
		case 'p':
			cout << "please input the place you want to place(1~8) and the which object you want to place(1~4):";
			cin >> inp2>>inp3;
			cout << endl;
			obj[inp2-1] = inp3;
			break;
		case 'r':
			cout << "please input the place you want to remove(0~8)";
			cin >> inp2;
			cout << endl;
			obj[inp2-1] = 0;
			break;
		default:
			break;
		}
		left = 0, right = 0;
		for (i = 0; i < 4; i++)
			left += (4 - i)*obj[i];
		for (i = 4; i < 8; i++)
			right += (i - 3)*obj[i];
		sta = 0;
		if (left < right)
			sta = 2;
		else if (left > right)
			sta = 1;
		p(sta);
		cin >> inp;
	}
    return 0;
}

