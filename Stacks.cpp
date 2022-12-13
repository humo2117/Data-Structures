/*
	This program deals with a stack whose size is fixed by the user at the beginning.
	Then through a menu, keys can be pushed into the stack and popped out of the stack.
*/
#include<iostream>
using namespace std;

int main()
{
	int size=50, choice = 0, top=0;
	cout << "Enter size of stack you want : ";
	cin >> size;
	int stack[size];
	for (int i = 0; i < size; ++i)
	{
		stack[i]=0;
	}

	bool exit = false;

	while(!exit)
	{
		for (int i = 0; i < 100; ++i)
		{
			cout << "-";
		}
		cout << "\n\tChoose your option :\n\n1.Push\n\n2.Pop\n\n3.Display All\n\n Any other key to Exit\t:  ";
		cin >> choice;

		switch(choice)
		{
			case 1 :
				if(top==size)
					cout << "\tThe stack is FULL\n";
				else
				{
					cout << "\tEnter a number you want to enter in the stack : ";
					cin >> stack[top++];
					cout << "\tStack updated!!\n";
				}
				break;

			case 2 :
				if(top!=0)
					cout << "\tThe number over the top is : " << stack[--top] << endl;
				else
					cout << "The stack is EMPTY\n";
				break;

			case 3 :
				if(top!=0)
				{
					cout << "\n\tThe stack is :\n";
					for (int i = 1; i <= top; ++i)
					{
						cout << "\t  " << i << ". " << stack[i-1] << "\n";
					}
				}
				else
					cout << "The stack is EMPTY\n";
				break;

			default :
				exit = true;
		}
	}
	return 0;
}
