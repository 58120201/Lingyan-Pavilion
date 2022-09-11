//公有双重继承
#include<iostream>
using namespace std;
void itoa(int n,char*(&s))
{
	int i=0;
	for(int j=n;j!=0;j=j/10)
		i++;                           //i为位数
	s=new char[i+1];
	s[i]='\0';
	for(int m=i-1;n!=0;m--)
	{
		int k=n%10;
		s[m]=k+48;
		n=n/10;
	}
}
class Date
{
protected:
	int year,month,day;
public:
	Date(int y=0,int m=0,int d=0)
	{
		year=y,month=m,day=d;
	}
	void setDate(int y,int m,int d)
	{
		year=y,month=m,day=d;
	}
	void getDate(char*(&date))
	{
		char *y=0,*m=0,*d=0;
		itoa(year,y);
		itoa(month,m);
		itoa(day,d);
		strcat(date,y);
		strcat(date,"/");
		strcat(date,m);
		strcat(date,"/");
		strcat(date,d);
	}
};
class Time
{
protected:
	int hour,minute,second;
public:
	Time(int h=0,int m=0,int s=0)
	{
		hour=h,minute=m,second=s;
	}
	void setTime(int h,int m,int s)
	{
		hour=h,minute=m,second=s;
	}
	void getTime(char*time)
	{
		char *h=0,*m=0,*s=0;
		itoa(hour,h);
		itoa(minute,m);
		itoa(second,s);
		strcat(time,h);
		strcat(time,":");
		strcat(time,m);
		strcat(time,":");
		strcat(time,s);
	}
};
class DateTime:public Date,public Time
{
public:
	DateTime(int y=0,int mo=0,int d=0,int h=0,int mi=0,int s=0):Date(y,mo,d),Time(h,mi,s){}	
	void setDateTime(int y,int mo,int d,int h,int mi,int s)
	{
		year=y;
		month=mo;
		day=d;
		hour=h;
		minute=mi;
		second=s;
	}
	void getDateTime(char*(&datetime))
	{
		char dat[11]={0},ti[9]={0};
		char* date=dat,* time=ti;
		getTime(time);
		getDate(date);
		strcpy(datetime,dat);
		strcat(datetime," ");
		strcat(datetime,ti);
	}
};
int main()
{
	DateTime x(2021,5,18,16,45,30);
	char dati[30]={0};
	char* datetime=dati;
	x.getDateTime(datetime);
	cout<<datetime<<endl;
	cout<<"重设日期时间：\n";
	int y,mo,d,h,mi,s;
	cin>>y>>mo>>d>>h>>mi>>s;
	x.setDateTime(y,mo,d,h,mi,s);
	x.getDateTime(datetime);
	cout<<datetime<<endl;
	return 0;
}