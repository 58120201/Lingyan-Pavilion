#include<iostream>
using namespace std;

int fun(int a[], int x)
{
	int i;
	for (i = 0; x > 0;)
	{
		a[i++] = x % 2;
		x = x / 2;
	}
	return i;
}

int main()
{
	int a[20], i, x, n;
	cin >> x;
	n = fun(a, x);
	for (i = n - 1; i >= 0; i--)
	{
		cout << a[i];
		if ((i + 4) % 4 == 0)cout << " ";
	}
	return 0;
}