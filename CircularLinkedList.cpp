/*
	This program creates and displays a circular-linked list.
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

struct cll {
	int data;
	struct cll *next;
}*s;

void create(int n)
{
	s = (struct cll*)malloc(sizeof(struct cll));
	struct cll *p=s, *Node1;

	if(s==NULL)
	{
		cout << "No memory allocated to the circular linked list\n";
	}
	else
	{
		cout << "Data at node 1 : ";
		cin >> s->data;

		for(int i=2; i<=n; i++)
		{
			Node1 = (struct cll*)malloc(sizeof(struct cll));
            if(Node1 == NULL)
            {
                cout << "Memory not located";
                break;
            }
            else
            {
				cout << "Data at node " << i << " : ";
				cin >> Node1->data;

                Node1->next = s;
				p->next = Node1;
				p = p->next;
			}
		}
	}
}

void display(int n)
{
	struct cll *p=s;
	cout << "\n\nCircular linked list :\n";
	for(int i=1; i<=n; i++)
	{
		cout << "\t" << i << ". " << p->data << endl;
		p = p->next;
	}
}

int main()
{
	int n;
	cout << "Number of nodes : ";
	cin >> n;
	create(n);
	display(2*n+2);
	return 0;
}
