//使用抽象类和纯虚函数，实现不同几何图形面积的实现
#include<iostream>
#define pi 3.14
using namespace std;
class shape
{
public:
	virtual double area()=0;
	virtual void setdata(double,double=0)=0;
};
class triangle:public shape
{
	double w;
	double h;
public:
	triangle(double x=0,double y=0){w=x,h=y;}
	double area(){return w*h/2;}
	void setdata(double x,double y){w=x,h=y;}
};
class rectangle:public shape
{
	double w;
	double h;
public:
	rectangle(double x,double y){w=x,h=y;}
	double area(){return w*h;}
	void setdata(double x,double y){w=x,h=y;}
};
class square:public shape
{
	double s;
public:
	square(double x){s=x;}
	double area(){return s*s;}
	void setdata(double x,double y){s=x;}

};
class circle:public shape
{
	double r;
public:
	circle(double x){r=x;}
	double area(){return pi*r*r;}
	void setdata(double x,double y){r=x;}
};
int main()
{
	double sum=0;
	shape *p;

	p=new triangle(0,0);
	(*p).setdata(2,2);
	sum+=(*p).area();
	cout<<"三角形面积为："<<(*p).area()<<endl;
	delete p;

	p=new rectangle(0,0);
	(*p).setdata(2,2);
	sum+=(*p).area();
	cout<<"长方形面积为："<<(*p).area()<<endl;
	delete p;

	p=new square(0);
	(*p).setdata(2,0);
	sum+=(*p).area();
	cout<<"正方形面积为："<<(*p).area()<<endl;
	delete p;

	p=new circle(0);
	(*p).setdata(2,0);
	sum+=(*p).area();
	cout<<"圆形面积为："<<(*p).area()<<endl;
	delete p;
	cout<<"总面积为："<<sum<<endl;
	return 0;
}