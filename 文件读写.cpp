//将w1.txt和w2.txt中的数字按升序在w3.txt中输出
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	fstream in1;
	fstream in2;
	fstream out;
	in1.open("w1.txt");
	in2.open("w2.txt");
	out.open("w3.txt");
	int a[4],b[6];
	int i=0,j=0;
	for(;i<4;i++)
		in1>>a[i];
	for(;j<6;j++)
		in2>>b[j];
	i=j=0;
	while(i<4&&j<6)
	{
		if(a[i]>b[j])
		{
			out<<b[j]<<" ";
			j++;
		}
		else if(a[i]<=b[j])
		{
			out<<a[i]<<" ";
			i++;
		}
	}
	if(i<4)
		for(;i<4;i++)
			out<<a[i]<<" ";
	if(j<6)
		for(;j<6;j++)
			out<<b[j]<<" ";
	out.close();
	return 0;
}