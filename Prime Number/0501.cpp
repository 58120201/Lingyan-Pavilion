#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int x,y,z,i=0,step=0;
	for (x = 101; x <= 200;)
	{
		z = sqrt(x);
		for (y = 2; y <= z; y = y + 1)
		{if (x % y == 0)break;}
		if (y >=z + 1)
		{
			cout << x << '\t';
			i = i + 1;
			step = step + 1;
			if (step == 6)
			{
				cout << '\n';
				step = 0;
			}
		}
		x = x + 2;
	}
	cout << '\n'<<"¹²ÓÐ"<<i<<"¸ö";
	return 0;
}