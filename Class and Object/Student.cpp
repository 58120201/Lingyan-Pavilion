//��������̣����á�ѧ�����࣬������������ѧ�źͳɼ���ǰ����Ϊָ��
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
		cout<<"����"<<setw(10)<<"ѧ��"<<setw(12)<<"��ѧ"<<setw(5)<<"Ӣ��"<<setw(5)<<"����"<<setw(5)<<"C++"<<setw(12)<<"ƽ����\n";
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
	cout<<"������Ϣ��\n";
	stud.output();
	return 0;
}