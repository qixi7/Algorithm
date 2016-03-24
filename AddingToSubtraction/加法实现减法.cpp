#include <iostream>
using namespace std;

int negate(int b)
{
	int value = (b < 0 ? 1 : -1);
	int n = 0;
	while (b != 0)
	{
		n += value;
		b += value;
	}
	return n;
}

int main()
{
	int a = 1;
	int b = -2;
	cout << a + negate(b) << endl; 
	return 0;
}