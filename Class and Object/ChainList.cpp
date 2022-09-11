//��������̸�д����
#include<iostream>
#include<iomanip>
using namespace std;
struct Node
{
	int num;
	Node* next;
};
class List
{
	Node* head;
public:
	List() { head->next = NULL; }
	List(int a[]);
	~List();
	void print();
	void reverse();
	void sort();
	void insert(Node* p);
	void del_bin(Node* x);
	void cutoff(int a);
	int count();
};
int main()
{
	int a[20] = { 0 };
	cout << "�����������֣���-1��β\n";
	for (int i = 0; i < 20; i++)
	{
		cin >> a[i];
		if (a[i] == -1)
			break;
	}
	cout << "��������Ϊ��\n";
	List list(a);
	list.print();
	cout << "������ת\n";
	list.reverse();
	list.print();
	cout << "��������\n";
	list.sort();
	list.print();
	cout << "����Ҫ�������\n";
	Node* p = new Node;
	cin >> p->num;
	cout << "���������Ϊ\n";
	list.insert(p);
	list.print();
	cout << "����ɾ����\n";
	int x;
	cin >> x;
	cout << "ɾ��������Ϊ\n";
	list.cutoff(x);
	list.print();
	cout << "��ʱ�ڵ���Ϊ\n";
	cout << list.count();
	//list.~List();

	return 0;
}
List::List(int a[])
{
	int i = 0;
	Node* p1, * p2;
	while (a[i] != -1)
	{
		p1 = new Node;
		p1->num = a[i];
		if (i == 0)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		i++;
	}
	if (a[i] == -1 && i == 0)
		head = NULL;
	p1->next = NULL;
}

List::~List()
{
	if (head == NULL) return;
	Node* p = head->next;
	while (p)
	{
		delete head;
		head = p;
		p = p->next;
	}
	delete head;
}

void List::print()
{
	if (head == 0)
		cout << "����Ϊ��\n";
	else
	{
		Node* p = head;
		while (p)
		{
			cout << p->num << " ";
			p = p->next;
		}
		cout << endl;
	}
}

void List::reverse()
{
	Node* p = head, * p1 = NULL, * temp = NULL;
	while (p)
	{
		head = new Node;
		p1 = head;
		p1->num = p->num;
		p = p->next;                  //��p����head��¼ԭ����
		p1->next = temp;
		temp = p1;
	}
	delete p;
}

void List::sort()
{
	Node* p1 = head, * p2 = p1->next;
	for (; p1->next; p1 = p1->next)
	{
		for (p2 = p1->next; p2; p2 = p2->next)
		{
			if (p1->num > p2->num)
			{
				int t = p1->num;
				p1->num = p2->num;
				p2->num = t;
			}
		}
	}
}

void List::insert(Node* p)
{
	if (!head)
	{
		head = p;
		p->next = NULL;
		return;
	}
	Node* p1 = head, * p2 = p1->next;
	while ((p1->num) < (p->num) && p1->next)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (p1->num >= p->num)
	{
		p2->next = p;
		p->next = p1;
	}
	else
	{
		p1->next = p;
		p->next = NULL;
	}
}

void List::del_bin(Node* x)
{
	Node* p;
	while (x)
	{
		p = x;
		x = x->next;
		delete p;
	}
}

void List::cutoff(int a)
{
	Node* p1 = head, * p2 = head, * bin = NULL;
	while (p1 && p1->next)
	{
		while (p1->num >= a && p1->next != NULL)
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (p1->num < a)
		{
			if (p1 == head)
			{
				head = p1->next;
				p2 = p1 = head;
			}
			else
			{
				p2->next = p1->next;
				p1 = p2->next;
			}
		}
	}
}

int List::count()
{
	int a = 0;
	Node* p = head;
	while (p)
	{
		a++;
		p = p->next;
	}
	return a;
}