#include<iostream>
using namespace std;
void Bottom_cut_rod(int Income[],int Solution[],int length,int PriceList[10])
{
	int Maxincome;
	Income[0] = 0;
	for ( int j = 1; j <= length; j++ )
	{
		Maxincome = -666;
		for (int i = 1; i <= j; i++)
		{
			if (Maxincome < PriceList[i] + Income[j - i])
			{
				Maxincome = PriceList[i] + Income[j - i];
				Solution[j] = i;
			}
		}
		Income[j] = Maxincome;
	}
}
void Print_cut_rod_solution(int Income[],int Solution[],int length,int PriceList[10])
{
	Bottom_cut_rod(Income,Solution,length,PriceList);
	while (length > 0)
	{
		cout << Solution[length] << endl;
		length = length - Solution[length];
	}
}
void main()
{
	int Income[10] = {0};
	int Solution[10] = {0};
	int length = 10;
	int PriceList[10] = {1,5,8,9,10,17,17,20,24,10};
	Print_cut_rod_solution(Income,Solution,length,PriceList);
	cout << "最优收益为:";
	for (int i = 0; i < length; i++)
	{
		cout << Income[i] << ' ';
	}
	cout << endl;
	cout << "最切割方案为:";
	for (int i = 0; i < length; i++)
	{
		cout << Solution[i] << ' ';
	}
	cout << endl;
}