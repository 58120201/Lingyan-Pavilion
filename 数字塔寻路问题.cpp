#include<iostream>
#include<string>
using namespace std;
int main()
{
	int a[5][5]={
		9,15,8,5,16,
		12,6,9,4,0,
		10,18,10,0,0,
		2,7,0,0,0,
		19,0,0,0,0};
	int b[5][5];
	memcpy(b,a,sizeof(a));
	for(int i=3;i>=0;i--)
		for(int j=3-i;j>=0;j--)
			a[i][j]=b[i][j]+max(a[i+1][j],a[i][j+1]);
	cout<<"����Ϊ��"<<a[0][0]<<endl;
	cout<<"·��Ϊ��"<<b[0][0];
    for(int n=1,i=0;n<=4;n++)
	{
		i=(a[i+1][n-i-1]>a[i][n-i])?i+1:i;
		cout<<" -> "<<b[i][n-i];
	}
	return 0;
}