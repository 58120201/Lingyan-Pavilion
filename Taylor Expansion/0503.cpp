#include<iostream>
using namespace std;

int main()
{
	double x, a, i = 1, cos = 1, sign = 1;
	cin >> x;
	for (a = 1; a >= 1e-4;)
	{
		a = a * (x * x / (i * (i + 1)));
		i = i + 2;
		sign = sign * (-1);
		cos = cos + sign*a;
	}
	cout << cos;
}