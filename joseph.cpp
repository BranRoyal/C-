// joseph.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include<iostream>  
#include<iomanip>  

using namespace std;

int nextRound(int *p, int n, int r, int position)    //�� postion ����һ��δ���ֵ�λ������  
{
	int i = 0;

	while (true)
	{
		if (position == n - 1)   //��ֹ���� position Ϊ0�����  
			position = n;
		else
			position = (position + 1) % n;

		if (p[position] == 0)  //positionλ�õ���δ�뿪  
			i++;

		if (i == r)
			return position;
	}
}

int Joseph(int n, int r)     //�ܹ�n���ˣ�������r�����뿪
{
	int position;

	if (r%n == 0)    //��ֹ����mΪn�ı������Ӷ�positionΪ��  
		position = n;
	else
		position = r%n;
	int *p = new int[n + 1];
	int i;
	for (i = 1; i <= n; i++)   //��ʼ�����飬0��ʾδ�뿪,1��ʾ�뿪
		p[i] = 0;
	int count = n;       //count��ʾʣ������  
	cout.setf(ios::left);
	cout << "�뿪��˳����:" << endl;
	while (count>1)
	{
		cout << setw(4) << position;
		p[position] = 1; //�������ñ�־  
		count--;      //count����ʣ������  

		position = nextRound(p, n, r, position);     //����ȷ����һ���뿪����  
	}

	delete[] p;
	return position;

}


int main()
{
	int n, m;
	do {
		cout << "������������";
		cin >> n;
		cout << "�����ڼ��������뿪��";
		cin >> m;
		if (n <= 0 || m <= 0)
			cout << "��������������⣡����������" << endl;
	} while (n <= 0 || m <= 0);
	int position = Joseph(n, m);
	cout << position << endl << endl;
	system("pause");
	return 0;
}

