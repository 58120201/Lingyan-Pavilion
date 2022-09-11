//��������أ��������Ա��࣬ʵ�����Ա��ƴ��(+)�͸�ֵ(=)
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
			cout<<"�±�Խ��\n";
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
	cout<<"���Ա�1����Ϊ��"<<list1.Len()<<endl;
	cout<<"���Ա�1Ԫ�ظ���Ϊ��"<<list1.Elem()<<endl;
	cout<<"���Ա�1�е�Ԫ���У�";
	list1.print();
	ListClass list2(3);
	for(int i=0;i<3;i++)
		list2.Elem(rand()%10);
	cout<<"���Ա�2����Ϊ��"<<list2.Len()<<endl;
	cout<<"���Ա�2Ԫ�ظ���Ϊ��"<<list2.Elem()<<endl;
	cout<<"���Ա�2�е�Ԫ���У�\n";
	list2.print();
	cout<<"��1+��2��\n";
	list1+list2;
	list1.print();
	cout<<"��2=��1:\n";
	list2=list1;
	list2.print();
	return 0;
}