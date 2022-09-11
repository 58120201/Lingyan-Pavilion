//��������أ�����������+-=+=
#include<iostream>
using namespace std;
class Complex
{
	double real;
	double image;
public:
	Complex(double r=0,double i=0)
	{
		real=r;
		image=i;
	}
	Complex &operator=(const Complex& a);
	Complex &operator+=(Complex& a);
	void show();
	friend Complex operator+(Complex&,Complex&);
	friend Complex operator-(Complex&,Complex&);
};
Complex& Complex::operator=(const Complex& a)
	{
		if(this==&a)
			return *this;
		real=a.real;
		image=a.image;
		return *this;
	}
Complex& Complex::operator+=(Complex& a)
	{
		real+=a.real;
		image+=a.image;
		return *this;
	}
void Complex::show()
{
	if(image>0)
		cout<<real<<"+"<<image<<"i"<<endl;
	else if(image<0)
		cout<<real<<image<<"i"<<endl;
	else if(image=0)
		cout<<real<<endl;
}
Complex operator+(Complex& a,Complex& b)
{
	return Complex(a.real+b.real,a.image+b.image);
}
Complex operator-(Complex& a,Complex& b)
{
	return Complex(a.real-b.real,a.image-b.image);
}
int main()
{
	Complex a(1,2),b(4,5),c,d;
	c=a+b;
	d=b-a;
	cout<<"aΪ:\n";
	a.show();
	cout<<"bΪ:\n";
	b.show();
	cout<<"cΪ:\n";
	c.show();
	cout<<"dΪ:\n";
	d.show();
	return 0;
}