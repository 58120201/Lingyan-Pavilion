#include<iostream>
using namespace std;

int main()
{
	int n, i, j;
	cout << "ÇëÊäÈëÍ¼·ù±ß³¤";
	cin >> n;
	if (n % 2 == 0)
	{
		cout << "error!";
		return 0;
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i + j == ((n + 1) / 2) + 1 || i == ((n + 1) / 2) + j - 1 || i + j == (3 * n + 1) / 2 || j == ((n + 1) / 2) + i - 1)
				cout << "*";
			else
				cout << " ";
		}
		cout << '\n';
	}
	return 0;
}