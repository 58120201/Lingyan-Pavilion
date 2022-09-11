//运算符重载，操作线性表类，实现线性表的拼接(+)和赋值(=)
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
class ListClass
{
	int *ListPtr;
	int nLen;
	int nElem;
public:
	ListClass(int n=10)
	{
		nElem=0;
		nLen=n;
		if(n)
			ListPtr=new int[n];
		else
			ListPtr=NULL;
	}
	~ListClass()
	{
		delete [nLen]ListPtr;
	}
	int Elem(int);
	int Elem(void){return nElem;}
	int Len(void){return nLen;}
	int GetElem(int i)
	{
		if(i>=0&&i<nElem)
			return ListPtr[i];
		else
			cout<<"下标越界\n";
	}
	void print()
	{
		for(int i=0;i<nElem;i++)
		{
			cout<<ListPtr[i]<<" ";
		}
		cout<<endl;
	}
	ListClass& operator+(ListClass&);
	ListClass& operator=(ListClass&);
};
int ListClass::Elem(int n)
{
	if(nLen==nElem)
	{
		int *newptr;
		newptr=new int [nLen+10];
		for(int i=0;i<nElem;i++)
		{
			newptr[i]=ListPtr[i];
		}
		delete[nLen]ListPtr;
		nLen+=10;
		ListPtr=newptr;
	}
	ListPtr[nElem++]=n;
	return(nElem);
}
ListClass& ListClass::operator+(ListClass& x)
{
	int *newptr;
	newptr=new int [nLen+x.nElem];
	int i=0;
	for(;i<nElem;i++)
		newptr[i]=ListPtr[i];
	for(int m=0;m<x.nElem;i++,m++)
		newptr[i]=x.ListPtr[m];
	delete[nLen]ListPtr;
	nLen+=x.nElem;
	nElem+=x.nElem;
	ListPtr=newptr;
	return *this;
}
ListClass& ListClass::operator=(ListClass& x)
{
	if(nLen<x.nLen)
	{
		int* newptr;
		newptr=new int[x.nLen];
		for(int i=0;i<x.nLen;i++)
			newptr[i]=x.ListPtr[i];
		delete[nLen]ListPtr;
		ListPtr=newptr;
		nLen=x.nLen;
		nElem=x.nElem;
		return *this;
	}
	else if(nLen>=x.nLen)
	{
		for(int i=0;i<x.nLen;i++)
			ListPtr[i]=x.ListPtr[i];
		nLen=x.nLen;
		nElem=x.nElem;
		return *this;
	}
}
int main()
{
	srand(unsigned(time(0)));
	ListClass list1(10);
	for(int i=0;i<10;i++)
		list1.Elem(rand()%10);
	cout<<"线性表1长度为："<<list1.Len()<<endl;
	cout<<"线性表1元素个数为："<<list1.Elem()<<endl;
	cout<<"线性表1中的元素有：";
	list1.print();
	ListClass list2(3);
	for(int i=0;i<3;i++)
		list2.Elem(rand()%10);
	cout<<"线性表2长度为："<<list2.Len()<<endl;
	cout<<"线性表2元素个数为："<<list2.Elem()<<endl;
	cout<<"线性表2中的元素有：\n";
	list2.print();
	cout<<"表1+表2：\n";
	list1+list2;
	list1.print();
	cout<<"表2=表1:\n";
	list2=list1;
	list2.print();
	return 0;
}