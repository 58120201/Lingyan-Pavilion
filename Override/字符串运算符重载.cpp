//运算符重载，操作字符类，实现字符的复制（=）、拼接（+和+=）与比较（==）
#include<iostream>
#include<cstring>
using namespace std;
class String
{
	char* str;
	int len;
public:
	String(char*);
	String(String&);
	~String();
	void set(char*);
	void show();
	int getlen(){return len;}
	void delchar(char);
	String& operator=(String&);
	String& operator+=(String&);
	bool operator==(String&);
	friend String operator+(String&,String&);
};
String::String(char* a=NULL)
{
	if(a==NULL)
	{
		str=NULL;
		len=0;
	}
	else
	{
		str=new char[strlen(a)+1];
		strcpy(str,a);
		len=strlen(a);
	}
}
String::String(String& a)
{
	if(a.str==NULL)
		str=NULL;
	else
	{
		str=new char[a.len+1];
		strcpy(str,a.str);
	}
	len=a.len;
}
String::~String()
{
	delete[]str;
}
void String::set(char* a)
{
	if(a==NULL)
		str=NULL;
	else
	{
		str=new char[strlen(a)+1];
		strcpy(str,a);
	}
	len=strlen(a);
}
void String::show()
{
	cout<<str<<endl;
}
void String::delchar(char x)
{
	for(int i=0;i<len;i++)
	{
		if (*(str+i)==x)
		{
			int j=i;
			for(;j<len-1;j++)
				*(str+j)=*(str+j+1);
			*(str+j)='\0';
			len=len-1;
			i--;
		}
	}
}
String& String::operator=(String& s)
{
	if(this==&s)
		return *this;
	if(str)delete[]str;
	if(s.str)
	{
		str=new char[strlen(s.str)+1];
		strcpy(str,s.str);
	}
	len=strlen(s.str);
	return *this;
}
String& String::operator+=(String& s)
{
	String t(str);
	str=new char[len+s.len+1];
	strcpy(str,t.str);
	strcat(str,s.str);//<=>strcpy(str+t.len,str);
	len=t.len+s.len;
	return *this;
}
bool String::operator==(String& s)
{
	if(strcmp(s.str,str)==0)
		return true;
	else
		return false;
}
String operator+(String& a,String& b)
{
	String t;
	t.str=new char[a.len+b.len+1];
	strcpy(t.str,a.str);
	strcat(t.str,b.str);
	t.len=a.len+b.len;
	return t;
}
int main()
{
	String a("Helloworld"),b("Boodbye"),c;
	c=a;
	cout<<"输出1则复制成功\n";
	cout<<(a==c)<<endl;
	cout<<"第一次拼接字符：\n";
	c+=b;
	c.show();
	cout<<"第二次拼接字符：\n";
	a=a+b;
	a.show();
	cout<<"删除字母l\n";
	a.delchar('l');
	a.show();
	return 0;
}