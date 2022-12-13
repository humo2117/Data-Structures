/*
	Perform stack operations using Linked List implementation.
*/
#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
}*s;

int Max=0, Size=1;
void create()
{
	cout << "\n\tEnter size of stack : ";
	cin >> Max;
}

void push(int data)
{
	if(Max==Size)
	{
		cout << "\n\t\tSTACK FULL!!";
		return;
	}
	if(s==NULL)
	{
		s = (struct node*)malloc(sizeof(struct node));
		s->data = data;
		s->next = NULL;
		cout << "\n" << data << " pushed into the stack";
		return;
	}

	struct node*p=s,*Node2;
	Node2 = (struct node*)malloc(sizeof(struct node));
	if(p==NULL)
	{
		cout << "\nMemory not located";
	}
	else
	{
		Node2->data=data;
		Node2->next=NULL;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=Node2;
		cout << "\n" << data << " pushed into the stack";
	}
	Size++;
}

int pop()
{
	if(s==NULL)
	{
		cout << "\nStack empty!!";
		return -1;
	}

	struct node *p=s, *q;
	int data;
	if(p->next==NULL)
	{
		data = p->data;
		free(p);
		s = NULL;
	}
	else
	{
		while(p->next->next!=NULL)
			p = p->next;
		q = p->next;
		data = q->data;
		p->next = NULL;
		free(q);
	}
	return data;
}

void display()
{
	struct node*p;
	if(s==NULL)
	{
		cout << "\nEMPTY LIST";
	}
	else
	{
		p = s;
		int i=1;
		while(p!=NULL)
		{
			cout << "\t" << i << ". " << p->data << endl;
			p=p->next;
			i++;
		}
	}
}

int main()
{
	create();
	int choice=1, data=0;
	while(choice)
	{
		cout << "\n\n\n";
		for (int i = 0; i < 80; ++i)
		{
			cout << "-";
		}
		cout << "\n\tChoose your option :\n\n1.Push\n\n2.Pop\n\n3.Display All\n\n Any other key to Exit\t:  ";
		cin >> choice;

		switch(choice)
		{
			case 1 :
				cout << "\nEnter a number you want to enter in the stack : ";
				cin >> data;
				push(data);
				break;

			case 2 :
				if((data=pop())!=-1)
					cout << "\nData popped = " << data;
				break;

			case 3 :
				display();
				break;

			default :
				choice = 0;
				break;
		}
	}
	return 0;
}
