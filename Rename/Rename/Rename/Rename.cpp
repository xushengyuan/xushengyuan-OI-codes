// Rename.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <cstring>
using namespace std;

char nametemp[10];
char newname[50];
char openname[50];
int n;
int len_int(int x)
{
	int t = x,len=0;
	while (t >= 10)
	{
		len++;
		t /= 10;
	}
	len++;
	return len;
}
void itoc(int x)
{
	int len = 0, i,t = x;
	len = len_int(x);
	for (i = len - 1; i >= 0; i--)
	{
		nametemp[i] ='0'+ t % 10;
		t /= 10;
	}
	nametemp[len] = '\0';
	return;
}
int main()
{
	FILE* in;
	int i, result = 0;
	int a;
	cout << "请输入文件个数(从0开始编号):";
	cin >> n;
	cout << "请输入文件名来源文件:";
	scanf_s("%s", openname,50);
	fopen_s(&in, openname, "r");
	for (i = 1; i <= n; i++)
	{
		fscanf_s(in, "%s", newname,50);
		itoc(i);
		strcat_s(nametemp, ".wav");
		strcat_s(newname, ".wav");
		rename(nametemp,newname);
	}
	rename("1.txt", "2.txt");
    return 0;
}

