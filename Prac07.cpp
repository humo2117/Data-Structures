/*
	Perform Stack operations using Array implementation. Use Templates.
*/
#include<iostream>
using namespace std;

template <class t>
class stack
{
	int top;
	public:
		int s[2];
		stack()
		{
			top=-1;
		}
		void push(t item);
		t pop();
};

template <class t>
void stack<t>::push(t item)
{
	if(top>5)
		cout<<("\nStack full!!");
	else
		s[++top]=item;
}

template <class t>
t stack<t>::pop()
{
	if (top < 0)
	{
		cout<<("\nStack Empty!!");
		return -1;
	}
	else
	{
		int y = s[top--];
		return y;
	}
}

int main()
{
	stack<int> obj;

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
				obj.push(data);
				break;

			case 2 :
				if((data=obj.pop())!=-1)
					cout << "\nData popped = " << data;
				break;

//			case 3 :
//				display();
//				break;

			default :
				choice = 0;
				break;
		}
	}
	return 0;
}
