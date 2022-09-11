#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
template <typename T>
class Array
{
private:
	T* data;
	int size;
public:
	Array(T* x=0,int s=0);
	~Array();
	Array(Array& x);
	void show();
};
template<typename T>
Array<T> ::Array(T* x, int s)
{
	data=new T[s];
	for(int i=0;i<s;i++)
		*(data+i)=*(x+i);
	size=s;
}
template<typename T>
Array<T>::Array(Array& x)
{
	data=new T[x.size];
	for(int i=0;i<x.size;i++)
		*(data+i)=*(x.data+i);
	size=x.size;
}
template<typename T>
Array<T>::~Array()
{
	if(data)delete[]data;
}
template<typename T>
void Array <T> ::show()
{
	for(int i=0;i<size;i++)
		cout<<*(data+i)<<"  ";
	cout<<endl;
}
int main()
{
	srand(unsigned(time(0)));
	int m,n,mn;

	cout<<"输入整形数组元素个数：\n";
	cin>>m;
	int* p1=new int[m];
	for(int i=0;i<m;i++)
		*(p1+i)=rand()%10;

	cout<<"输入实数数组元素个数：\n";
	cin>>n;
	float* p2=new float[n];
	cout<<"输入实数数组元素：\n";
	for(int i=0;i<m;i++)
		cin>>*(p2+i);
	
	cout<<"输入char数组元素个数：\n";
	cin>>mn;
	char* p3=new char[mn];
	for(int i=0;i<mn;i++)
		*(p3+i)='a'+rand()%26;

	Array<int> intarray(p1,m);
	Array<float> floatarray(p2,n);
	Array<char> chararray(p3,mn);
	intarray.show();
	floatarray.show();
	chararray.show();
	Array<int> intarray2(intarray);
	intarray2.show();
	delete p1, p2, p3;
	return 0;
}