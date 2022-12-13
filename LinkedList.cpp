/*
	This program creates a linked list.
	Through a menu, then nodes can be added at the beginning or end or after a specific node.
	Also, any specific node in between or in the beginning or at the end can be deleted.
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	struct node* next;
}*s;

void createList(int n)
{
    struct node *Node1, *p;
    int data, i;

    s = (struct node *)malloc(sizeof(struct node));

    if(s == NULL)
    {
        cout << "Memory not located";
    }
    else
    {
        cout << "Enter the data at node 1: ";
        cin >> data;

        s->data = data; // Link data field with data
        s->next = NULL; // Link address field to NULL

        p = s;

        for(i=2; i<=n; i++)
        {
            Node1 = (struct node*)malloc(sizeof(struct node));
            if(Node1 == NULL)
            {
                cout << "Memory not located";
                break;
            }
            else
            {
                cout << "Enter the data at node " << i << ": ";
                cin >> data;

                Node1->data = data;
                Node1->next = NULL;
                p->next = Node1; 
                p = p->next; 
            }
        }

        cout << "LINKED-LIST CREATED SUCCESSFULLY\n";
	}
}

void insertAtBeginning(int data)
{
	struct node *p;
	p = (struct node*)malloc(sizeof(struct node));

	if(p == NULL)
	{
		cout << "Memory not located";
	}
	else
	{
		p->data = data;
		p->next = s;
		s = p;

		cout << "DATA INSERTED SUCCESSFULLY\n";
	}
}

void insertAtEnding(int data)
{
	struct node*p=s,*Node2;
	Node2 = (struct node*)malloc(sizeof(struct node));
	if(p==NULL)
	{
		cout << "Memory not located";
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
	}
}

bool insertInMid(int x, int data)
{
	struct node*p=s, *q;
	bool found = false;
	q=(struct node*)malloc(sizeof(struct node));
	for (; p->next!=NULL; p=p->next)
	{
		if(p->data==x)
		{
			q->next=p->next;
			p->next=q;
			q->data=data;
			found=true;
		}
	}
	return found;
}

bool deletex(int data)
{
	struct node*p=s;
	bool found = false;
	while(p->next!=NULL)
	{
		if(p->next->data==data)
		{
			found = true;
			p->next=p->next->next;
			break;
		}
		p=p->next;
	}
	return found;
}

void displayFull()
{
	struct node*p;
	if(s==NULL)
	{
		cout << "EMPTY LIST";
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

void deleteFirstNode()
{
	if(s!=NULL)
	{
		s = s->next;
		cout << "\nDeleted the first node...\n";
	}
	else
	{
		cout << "\nEmpty List!!!\n";
	}
}

void deleteLastNode()
{
	struct node *p=s;
	if(s!=NULL)
	{
		if(p->next!=NULL)
		{
			while(p->next->next!=NULL)
			{
				p = p->next;
			}
			p->next = NULL;
		}
		else
			s = NULL;
		cout << "\nDeleted the last node...\n";
	}
	else
	{
		cout << "\nEmpty List!!!\n";
	}
}
int main()
{
	int n, data, x, choice;
	cout << "Enter size of linked-list : ";
	cin >> n;
	createList(n);

	while(1)
	{
		cout << "\n\n\tM  E  N  U\n1. Insert x at beginning\n2. Insert x at end\n3. Insert x in middle\n4. Delete a specific value\n5. Delete the first node\n6. Delete the last node : ";
		cin >> choice;
		switch(choice)
		{
			case 1 :
			cout << "Enter data to be put in the beginning : ";
			cin >> data;
			insertAtBeginning(data);
			cout << "Inserted!!\n";
			displayFull();
			break;

			case 2 :
			cout << "Enter data to be put in the beginning : ";
			cin >> data;
			insertAtEnding(data);
			cout << "Inserted!!\n";
			displayFull();
			break;

			case 3 :
			cout << "Enter a number of the list : ";
			cin >> x;
			cout << "Enter data to be put after the first occurence of " << x << " : ";
			cin >> data;
			if(insertInMid(x,data))
				cout << "Inserted!!\n";
			else
				cout << x << " not found\n";
			displayFull();
			break;

			case 4 :
			printf("Enter a number of the list : ");
			cin >> x;
			if(deletex(x))
				cout << "Deleted " << x << "!!\n";
			else
				cout << x << " not found\n";
			displayFull();
			break;

			case 5 :
			deleteFirstNode();
			displayFull();
			break;

			case 6 :
			deleteLastNode();
			displayFull();
			break;

			default :
			break;
		}
	}
	return 0;
}
