/*
	Implement Linked List using templates
	Include functions for insertion, deletion and search of a number, reverse the list and concatenate two linked lists
	(include a function and also overload operator +).
*/
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

template <class T>
struct Node	{
	T data;
	Node *next;
};

template <class T>
void insertX(Node<T>**p, T data)
{
	Node<T>*temp= new Node<T>;
	if(temp==NULL)
	{
		cout << "\nOut of memory space";
		return;
	}
	temp->data = data;
	temp->next = NULL;
	if(*p==NULL)
		*p=temp;
	else
	{
		Node<T>*q= *p;
		while(q->next!=NULL)
			q=q->next;
		q->next=temp;
	}
}

template <class T>
void deleteX(Node<T>**p, T x)
{
	Node<T>*temp=*p;
	if(temp==NULL)
	{
		cout << "\nEmpty list";
		return;
	}

	bool found = true;
	if(temp->data==x)
	{
		if(temp->next==NULL)
		{
			(*p)=NULL;
			delete(temp);
			return;
		}
		delete(temp);
		(*p)=(*p)->next;
		cout << "\n" << x << " was deleted";
		return;
	}

	for(;temp->data!=x;temp=temp->next)
	{
		if(temp->next==NULL)
		{
			cout << "\n" << x << " was not found in the list";
			found = false;
			break;
		}
	}
	if(found)
	{
		temp = *p;
		for(;temp->next->data!=x;temp=temp->next);
		Node<T>*q=temp->next;
		temp->next=temp->next->next;
		delete(q);
		cout << "\n" << x << " was deleted";
		return;
	}
}

template <class T>
void search(Node<T> **p, T x)
{
	if((*p)==NULL)
	{
		cout << "Empty Linked-List";
		return;
	}

	Node<T>*s=*p;

	int index=1;
	bool found = true;
	for(;s->data!=x;s=s->next,index++)
	{
		if(s->next==NULL)
		{
			cout << "\n" << x << " was not found in the list";
			found = false;
			break;
		}
	}
	if(found)
	{
		cout << "\n" << x << " was found in the list at index " << index << " (starting from 1)";
	}
}

template <class T>
void reverse(Node<T> **p)
{
	if((*p)==NULL)
	{
		cout << "Empty Linked-List";
		return;
	}
	else if((*p)->next==NULL)
		return;
	Node<T>*a = NULL;
	Node<T>*b = *p;
	Node<T>*c = NULL;
	while(b!=NULL)
	{
		c=b->next;
		if(c==NULL)//If Buffer2 holds the last node
			*p=b;
		b->next=a;
		a=b;
		b=c;
	}
}

template <class T>
Node<T>* conc(Node<T>*faisal, Node<T>*saba)
{
	Node<T>*p=faisal;
	for(;p->next!=NULL;p=p->next);
	p->next=saba;
	return (faisal);
}

template <class T>
Node<T> & operator +(Node<T>&faisal, Node<T>&saba)
{
	Node<T>*p=&faisal;
	for(;p->next!=NULL;p=p->next);
	p->next=&saba;
	return faisal;
}

template <class T>
void print(Node<T> *p)
{
	while(p!=NULL)
	{
		cout << p->data << "->";
		p=p->next;
	}
	cout << "NULL" << endl;
}

int main()
{
	int data;
	Node<int>*n1=NULL;
	Node<int>*n2=NULL;
	cout << "\nSecondary linked list(automatically-generated for concatenation later) :\n   ";
		insertX(&n2,100);
		insertX(&n2,125);
		insertX(&n2,150);
		insertX(&n2,175);
		insertX(&n2,200);
	print(n2);

	cout << "\n\n--------------------------------Insert nodes-------------------------------\n";
	int more=1;
	while(more==1)
	{
		cout << "\nEnter data to be inserted : ";
		cin >> data;
		insertX(&n1,data);
		cout << "\nData inserted";
		cout << "\n   Insert more data : yes(1) or no(0) = ";
		cin >> more;
		more%=2;
	}
	cout << "\nLinked list : ";
	print(n1);

	cout << "\n\n--------------------------------Delete nodes-------------------------------\n";
	more=1;
	while(more==1)
	{
		cout << "\nEnter a data of the list : ";
		cin >> data;
		deleteX(&n1, data);
		cout << "\n   Delete more data : yes(1) or no(0) = ";
		cin >> more;
		more%=2;
	}
	cout << "\nLinked list : ";
	print(n1);

	cout << "\n\n----------------------Search for some data in the list---------------------\n";
	more=1;
	while(more==1)
	{
		cout << "\nEnter data to be searched : ";
		cin >> data;
		search(&n1, data);
		cout << "\n   Search more data : yes(1) or no(0) = ";
		cin >> more;
		more%=2;
	}
	cout << "\nLinked list : ";
	print(n1);

	cout << "\n\n--------------------------Reverse the linked-list--------------------------\n";
	reverse(&n1);
	cout << "\nLinked list reversed : ";
	print(n1);

	cout << "\n\n------------------------Concatenate the linked-list------------------------\n";
	int opt=-1;
	cout << "Using overaloaded + operator (0) / Using conc() function (1) : ";
	cin >> opt;
	opt%=2;
	if(opt==1)
		conc(n1,n2);
	else
		*n1+*n2;
	cout << "\nLinked list now : ";
	print(n1);
	return 0;
}
