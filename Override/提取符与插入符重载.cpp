//����<<��>>������дѧ��������ݳ�Ա
#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
class student
{
	char* name;
	char* no;
	int cpp;
	int math;
	int physics;
public:
	student(char* na,char* n,int c,int m,int p);
	student(student& stud);
	friend istream& operator>>(istream &,student &);
	friend ostream& operator<<(ostream &,student &);
	operator char*();
	operator int();
};
student::student(char* na=NULL,char* n=NULL,int c=0,int m=0,int p=0)
{
	name=new char[strlen(na)+1];
	strcpy(name,na);
	no=new char[strlen(n)+1];
	strcpy(no,n);
	cpp=c;
	math=m;
	physics=p;
}
student::student(student& stud)
{
	delete[]name;
	delete[]no;
	name=new char[strlen(stud.name)+1];
	no=new char[strlen(stud.no)+1];
	strcpy(name,stud.name);
	strcpy(no,stud.no);
	cpp=stud.cpp;
	math=stud.math;
	physics=stud.physics;
}
istream& operator>>(istream & in,student & stud)
{
	in.getline(stud.name,3);
	in.getline(stud.no,3);
	in>>stud.cpp>>stud.math>>stud.physics;
	return in;
}
ostream& operator<<(ostream & out,student & stud)
{
	out<<setw(5)<<"����"<<setw(5)<<"ѧ��"<<setw(10)<<"C++�ɼ�"<<setw(10)<<"��ѧ�ɼ�"<<setw(10)<<"����ɼ�\n";
	out<<setw(5)<<stud.name<<setw(5)<<stud.no<<setw(10)<<stud.cpp<<setw(10)<<stud.math<<setw(8)<<stud.physics<<endl;
	return out;
}
student::operator char *(){return name;}           //����ת������
student::operator int(){return cpp+math+physics;}  //����ת������
int main()
{
	student stud;
	char* p=NULL;
	int total=0;
	cout<<"���������������ѧ�š�C++�ɼ�����ѧ�ɼ�������ɼ���\n";
	cin>>stud;
	cout<<"���������Ϣ��\n";
	cout<<stud;
	p=stud;
	cout<<"���������\n";
	cout<<p<<endl;
	total=stud;
	cout<<"����ܷ֣�\n";
	cout<<total;
	return 0;
}