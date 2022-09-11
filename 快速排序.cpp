#include<iostream>
#include<cstdlib>
#include<ctime>
#define N 100
using namespace std;
//将字段第一个元素作为中值并返回位置信息，同时将简单区分中值左右字段
int getmid(int* arr,int low,int high)
{
	int temp=arr[low];
	while(low<high)
	{
		while(low<high&&temp<=arr[high])
			high--;
		arr[low]=arr[high];
		while(low<high&&temp>=arr[low])
			low++;
		arr[high]=arr[low];
	}
	arr[low]=temp;
	return low;
}
//快排
void Quicksort(int arr[],int left,int right)
{
	if(left<right)
	{
		int mid=getmid(arr,left,right);
		Quicksort(arr,left,mid-1);
		Quicksort(arr,mid+1,right);
	}
	else return;
};
int main()
{
	srand(unsigned(time(0)));
	int a[N];
	for(int i=0;i<N;i++)
		a[i]=rand()%10;
	for(int i=0;i<N;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	Quicksort(a,0,N-1);
	for(int i=0;i<N;i++)
		cout<<a[i]<<" ";
	return 0;
}
