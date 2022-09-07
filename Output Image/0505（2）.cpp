#include<iostream>
using namespace std;

int main()
{
	int m, n, m1, n1;
	cout << " " << "ÐÐ" << " " << "ÁÐ\n";
	cin >> m >> n;
	for (m1=1; m1 <= m; m1++)
	{
		for (n1 = 1; n1 <= n; n1++)
		{
			if (m1==1 || m1 == m || n1 == 1 || n1 == n)
			{
				cout << "*";
			}
			else
				cout << " ";
		}
		cout << '\n';
	}
	return 0;
}