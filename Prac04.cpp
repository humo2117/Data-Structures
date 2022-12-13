/*
	Implement Doubly Linked List using templates. Include functions for insertion, deletion and search of a number, reverse the list
*/
#include<iostream>
using namespace std;

template <class T>
struct Node	{
	T data;
	Node*next;
	Node*prev;
};

template <class T>
void insertX(Node<T>**p, T data)
{
	Node<T>*temp = new Node<T>;
	if(temp==NULL)
	{
		cout << "\nOut of memory space";
		return;
	}
	temp->data = data;
	temp->next = NULL;
	if((*p)==NULL)
	{
		(*p)=temp;
		temp->prev=NULL;
		return;
	}
	Node<T>*q=*p;
	for(;q->next!=NULL;q=q->next);
	q->next=temp;
	temp->prev=q;
}

template <class T>
void deleteX(Node<T>**p, T data)
{
	Node<T>*temp=*p;
	if(temp==NULL)
	{
		cout << "\nEmpty list";
		return;
	}

	bool found = true;
	if(temp->data==data)
	{
		if(temp->next==NULL)
		{
			(*p)=NULL;
			delete(temp);
			return;
		}
		(*p)=(*p)->next;
		(*p)->prev=NULL;
		delete(temp);
		cout << "\n" << data << " was deleted";
		return;
	}

	for(;temp->data!=data;temp=temp->next)
	{
		if(temp->next==NULL)
		{
			cout << "\n" << data << " was not found in the list";
			found = false;
			break;
		}
	}
	if(found)
	{
		temp = *p;
		for(;temp->next->data!=data;temp=temp->next);
		Node<T>*q=temp->next;
		temp->next->next->prev=temp->next->next->prev->prev;
		temp->next=temp->next->next;
		delete(q);
		cout << "\n" << data << " was deleted";
		return;
	}
}

template <class T>
void searchX(Node<T> **p, T data)
{
	if((*p)==NULL)
	{
		cout << "\nEmpty list";
		return;
	}

	Node<T>*s=*p;

	int index=1;
	bool found = true;
	for(;s->data!=data;s=s->next,index++)
	{
		if(s->next==NULL)
		{
			cout << "\n" << data << " was not found in the list";
			found = false;
			break;
		}
	}
	if(found)
	{
		cout << "\n" << data << " was found in the list at index " << index << " (starting from 1)";
	}
}

template <class T>
void reverseX(Node<T>** p)
{
	Node<T>* temp1= *p;
	Node<T>* temp2= NULL;

	while(temp1->next!=NULL)
	{
		temp2=temp1->prev;
		temp1->prev=temp1->next;
		temp1->next=temp2;

		temp1=temp1->prev;		
	}
	temp1->next=temp1->prev;
	temp1->prev=NULL;
	*p=temp1;
}

template <class T>
void printX(Node<T> *p)
{
	for(;p!=NULL;p=p->next)
		cout << p->data << " -> ";
	cout << "NULL" << endl;
}

int main()
{
	Node<int>*n1 = NULL;
	cout << "\nLinked list : ";
	printX(n1);

	int	more=1, data;
	cout << "\n\n--------------------------------Insert nodes-------------------------------\n";
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
	printX(n1);

	cout << "\n\n--------------------------------Delete nodes-------------------------------\n";
	more=1;
	while(more==1)
	{
		cout << "\nEnter data to be deleted : ";
		cin >> data;
		deleteX(&n1,data);
		cout << "\n   Delete more data : yes(1) or no(0) = ";
		cin >> more;
		more%=2;
	}
	cout << "\nLinked list : ";
	printX(n1);
	cout << "\nLinked list : ";
	printY(n1);

	cout << "\n\n----------------------Search for some data in the list---------------------\n";
	more=1;
	while(more==1)
	{
		cout << "\nEnter data to be searched : ";
		cin >> data;
		searchX(&n1,data);
		cout << "\n   Search more data : yes(1) or no(0) = ";
		cin >> more;
		more%=2;
	}

	cout << "\n\n--------------------------Reverse the linked-list--------------------------\n";
	reverseX(&n1);
	cout << "\nLinked list : ";
	printX(n1);
	return 0;
}
