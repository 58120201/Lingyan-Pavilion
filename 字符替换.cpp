#include<iostream>
#include<cstring>
using namespace std;
void trans(char*a,char*b,char*c)
{
	char*m=b,*n=c;
	char* p1=strstr(a,b),* p2=a;
	if(!p1)cout<<b<<"not found"<<endl;
	else
	{
		char*p=new char[strlen(a)-strlen(b)+strlen(c)+1];
		int i=0;
		for(;a<p1;i++,a++)
			*(p+i)=*a;

		if(p2!=p1)
			for(;*c;i++,c++)
				*(p+i)=*c;
		else strcpy(p,c);

		a=a+strlen(b);
		for(;*a;i++,a++)
			*(p+i)=*a;
		*(p+i)='\0';
		if(!strstr(p,b))
			cout<<p;
		else
			trans(p,m,n);
	}
}
int main()
{
	char a[]="jwc is worsen than the wc nearby";
	char b[]="wc";
	char c[]="xxx";
	trans(a,b,c);
	return 0;
}