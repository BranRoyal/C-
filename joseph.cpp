// joseph.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<iostream>  
#include<iomanip>  

using namespace std;

int nextRound(int *p, int n, int r, int position)    //从 postion 的下一个未出局的位置数起  
{
	int i = 0;

	while (true)
	{
		if (position == n - 1)   //防止出现 position 为0的情况  
			position = n;
		else
			position = (position + 1) % n;

		if (p[position] == 0)  //position位置的人未离开  
			i++;

		if (i == r)
			return position;
	}
}

int Joseph(int n, int r)     //总共n个人，报数到r的人离开
{
	int position;

	if (r%n == 0)    //防止出现m为n的倍数，从而position为零  
		position = n;
	else
		position = r%n;
	int *p = new int[n + 1];
	int i;
	for (i = 1; i <= n; i++)   //初始化数组，0表示未离开,1表示离开
		p[i] = 0;
	int count = n;       //count表示剩余人数  
	cout.setf(ios::left);
	cout << "离开的顺序是:" << endl;
	while (count>1)
	{
		cout << setw(4) << position;
		p[position] = 1; //重新设置标志  
		count--;      //count代表剩余人数  

		position = nextRound(p, n, r, position);     //重新确定下一次离开的人  
	}

	delete[] p;
	return position;

}


int main()
{
	int n, m;
	do {
		cout << "输入总人数：";
		cin >> n;
		cout << "数到第几个数就离开：";
		cin >> m;
		if (n <= 0 || m <= 0)
			cout << "输入的数据有问题！请重新输入" << endl;
	} while (n <= 0 || m <= 0);
	int position = Joseph(n, m);
	cout << position << endl << endl;
	system("pause");
	return 0;
}

