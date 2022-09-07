#include<iostream>
using namespace std;

int main()
{
	int n, m, a, b=1,a_,b_;
	cout<<" "<< "ÐÐ"<<" "<< "ÁÐ\n";
	cin >> n >> m;
	if (m % 2 == 0||n>=2*m+1)
	{
		cout << "error";
		return 0;
	}
	for (a = (m - 1) / 2; b <= n;)
	{
		for (a_ = 1; a_ <= a;)
		{
			cout << " ";
			a_ = a_ + 1;
		}
		for (b_ = 1;b_<=2*b-1;)
		{
			cout << "*";
			b_ = b_ + 1;
		}
		cout << '\n';
		b = b + 1;
		a = a - 1;
	}
	return 0;
}