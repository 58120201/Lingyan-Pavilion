//创建一个链表，数据域仅有一个数字,在（1）的基础上实现逆转（reverse）和排序（sort）功能
#include<iostream>
#include<iomanip>
using namespace std;
struct node
{
	int num;
	node *next;
};
node *creat_front()
{
	node *p1,*p2=NULL,*head=NULL;
	int a;
	cout<<"正在（向前）创建无序链表……\n";
	cout<<"请输入一个正整数，以-1结束：";
	cin>>a;
	while(a!=-1)
	{
		p1=new node;
		p1->num=a;
		if(head==NULL)
		{
			head=p2=p1;
			head->next=NULL;
		}
		else
		{
			p1->next=p2;
			head=p2=p1;
		}
		cout<<"请输入一个正整数，以-1结束：";
		cin>>a;
	}
	return(head);
}
node *creat_behind()
{
	node *p1,*p2=NULL,*head;
	int a;

	head=NULL;
	cout<<"正在（向后）创建无序链表……\n";
	cout<<"请输入一个正整数，以-1结束：";
	cin>>a;
	while(a!=-1)
	{
		p1=new node;
		p1->num=a;
		p1->next=NULL;
		if (!head)
			head=p2=p1;
		else
		{
			p2->next=p1;
			p2=p1;
		}
		cout<<"请输入一个正整数，以-1结束：";
		cin>>a;
	}
	return(head);
}
void print( const node*head)
{
	const node *p;
	p=head;
	cout<<"链表中的各节点数据为："<<endl;
	while(p!=NULL)
	{
		cout<<p->num<<" ";
		p = p->next;
	}
	cout<<endl;
}
const node* search(const node *head,int x)
{
	const node*p;
	p=head;
	while(p)
	{
		if(p->num==x)
			return p;
		p=p->next;
	}
	return NULL;
}
node *delete_one_node(node*head,int num)
{
	node*p1,*p2=NULL;
	if(head==NULL)
	{
		cout<<"链表为空，无结点可删!\n";
		return(NULL);
	}
	p1=head;
	while(p1->num!=num&&p1->next!=NULL)
	{
		p2=p1;
		p1=p1->next;
	}
	if(p1->num==num)
	{
		if(p1==head)
			head=p1->next;
		else
			p2->next=p1->next;
		delete p1;
		cout<<"删除结束！\n";
	}
	else
		cout<<"未找到可删结点！\n";
	return(head);
}
node *delete_many_node(node*head,int num)
{
	node*p=head;
	int n=0;
	while(p)
	{
		n++;
		p=p->next;
	}
	for(int i=0;i<=n;i++)
	{
		head=delete_one_node(head,num);
		if(!search(head,num))break;
	}
	return head;
}
void delChain(node *head)
{
	node *p;
	while(head)
	{
		p=head;
		head=head->next;
		delete p;
	}
}
node *reverse(node *head)                               //三指针，不新建链表           
{
	node *p1=head,*p2=NULL,*p3=NULL;
	p2=p1->next;
	p3=p2->next;
	p2->next=p1;
	p1->next=NULL;
	p1=p3;
	while(p1!=NULL)
	{
		p3=p1->next;
		p1->next=p2;
		p2=p3;
		if(p2==NULL)break;
		p3=p2->next;
		p2->next=p1;
		p1=p3;
	}
	if(p2==NULL)head=p1;
	else head=p2;
	return head;
}
node *reverse2(node *head)                    //两指针，新建链表
{
	node* p=head,*p1=NULL,*head_=NULL;
	while(p)
		{
			head=new node;
			p1=head;
			p1->num=p->num;
			p=p->next;
			p1->next=head_;
			head_=p1;
		}
	return (head_);
}
node *insert(node *head, node *p)//按升序插入节点
{
	if (head == NULL)
	{
		head = p;
		p->next = NULL;
		return head;
	}
	node *p1=head, *p2 = NULL;
	while (p->num > p1->num&&p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (p->num <= p1->num)
	{
		p->next = p1;
		if (head == p1) head = p;
	    else p2->next = p;
	}
	else
	{
		p1->next = p;
		p->next = NULL;
	}
	return head;
}
node *sort(node *head)                   //冒泡法
{
	node *p1=head,*p2=head,*p=NULL;
	for(;p1;p1=p1->next)
	{
		for(p2=p1;p2->next;p2=p2->next)
		{
			if(p2->num>(p2->next->num))
			{
				int t=p2->num;
				p2->num=p2->next->num;
				p2->next->num=t;
			}
		}
	}
	return head;
}
node *sort2(node *head)//摘节插入排序
{
	node* head1=NULL,*p=NULL,*p1 = NULL;
	p = head;
	while (p!=NULL)
	{
		p1 = new node;
		p1->num = p->num;
		head1=insert(head1, p1);
		p = p->next;
	}
	delChain(head);
	return head1;
}
node *sort3(node *head)          //提取重排
{
	node*p=head;
	int n=0,*x,i=0,j,l;
	while(p)
	{
		p=p->next;
		n++;
	}                        //记录长度
	x= new int[n];
	p=head;
	while(p)
	{
		x[i++]=p->num;
		p=p->next;
	}
	for(i=0;i<n;i++)
	{
		l=i;
		for(j=i+1;j<n;j++)
			if(x[j]<x[l]) l=j;
		if(l!=i)
		{int t=x[l];x[l]=x[i];x[i]=t;}
	}
	p=head;
	i=0;
	while(p)
	{
		p->num=x[i++];
		p=p->next;
	}
	delete x;
	return head;
}
int main()
{
	node *head;
	int a;
	cout<<"向后生成请输入‘0’：";
	cin>>a;
	if(a)
		head=creat_front();
	else
		head=creat_behind();
	print(head);

	cout<<"输入要删去的数：";
	cin>>a;
	head=delete_many_node(head,a);
	print(head);

	cout<<"输入要查的数：";
	cin>>a;
	if(search(head,a)!=NULL)
		cout<<"有的"<<endl;
	else
		cout<<"查了个寂寞"<<endl;

	cout<<"将链表逆转吧！\n";
	head=reverse2(head);
	print(head);

	cout<<"将链表排序\n";
	head=sort(head);
	print(head);

	delChain(head);
	cout<<"链表释放完毕，结束";
	return 0;
}