#include<iostream>
using namespace std;

int main()
{
	int n, m, a, b, a_, b_;                                              //a��bΪ�����������a_��b_Ϊ�Ʋ���
	cout << " " << "��" << " " << "��\n";
	cin >> n >> m;
	if (n % 2 == 0 || m % 2 == 0 || m < n)
	{
		cout << "error";
		return 0;
	}
	for (a = (m - 1) / 2, b = 1; a >= (m - n) / 2 && b <= n;)
	{
		for (a_ = 1; a_ <= a;)
		{
			cout << " ";
			a_ = a_ + 1;
		}
		for (b_ = 1; b_ <= b;)
		{
			cout << "*";
			b_ = b_ + 1;
		}
		cout << '\n';
		b = b + 2;
		a = a - 1;
	}                                                                                 //������

	for (a = 1 + (m - n) / 2, b = n - 2; (a <= (m - 1) / 2) && (b >= 1);)
	{
		for (a_ = 1; a_ <= a;)
		{
			cout << " ";
			a_ = a_ + 1;
		}
		for (b_ = 1; b_ <= b;)
		{
			cout << "*";
			b_ = b_ + 1;
		}
		cout << '\n';
		b = b - 2;
		a = a + 1;
	}                                                                                //������
	return 0;
}