#include<iostream>
using namespace std;

int function1(int n)
{
	int i, f = 1;
	for (i = 1; i <= n; i = i + 1)
	{
		f = f * i;
	}
	return f;
}
int function2(int n)
{
	int f = 0;
	if (n > 1)
		f = n * function2(n - 1);
	else if (n == 1 || n == 0)
		f = 1;
	return f;
}


int main()
{
	int n;
	cout << "n=";
	cin >> n;
	if (n < 0)
		cout << "error";
	else
		cout << function1(n) << endl << function2(n);
}