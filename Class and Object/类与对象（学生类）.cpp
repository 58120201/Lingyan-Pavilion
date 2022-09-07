//面向对象编程，设置“学生”类，数据域含有姓名学号和成绩，前两者为指针
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class student
{
	char* Name;
	char* No;
	int math;int english;int physics;int cpp;
public:
	void setnameno(char* name,char* no)
	{
		if(name)
		{
			Name=new char[strlen(name)+1];
			strcpy(Name,name);
		}
		else
			strcpy(Name," ");
		if(no)
		{
			No=new char[strlen(no)+1];
			strcpy(No,no);
		}
		else
			strcpy(No," ");
	}
	void setscore(int m,int e,int p,int c)
	{math=m;english=e;physics=p;cpp=c;}
	int total(){return math+english+physics+cpp;}
	int average(){return (total()/4);}
	void output()
	{
		cout<<"姓名"<<setw(10)<<"学号"<<setw(12)<<"数学"<<setw(5)<<"英语"<<setw(5)<<"物理"<<setw(5)<<"C++"<<setw(12)<<"平均分\n";
		cout<<Name<<setw(12)<<No<<setw(12)<<math<<setw(5)<<english<<setw(5)<<physics<<setw(5)<<cpp<<setw(10)<<average()<<endl;
	}
	~student()
	{
		if(No)delete[]No;
		if(Name)delete[]Name;
	}
};
int main()
{
	student stud;
	stud.setnameno("aa","G1220801");
	stud.setscore(100,100,100,100);
	cout<<"该生信息：\n";
	stud.output();
	return 0;
}