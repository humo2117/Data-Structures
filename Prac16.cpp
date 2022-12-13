/*
	WAP to reverse the order of the elements in the stack using additional stack.
*/
#include<iostream>
using namespace std;

int main()
{
	int size=0, top=0, top2=0;
	cout << "Enter size of stack you want : ";
	cin >> size;
	int stack[size]={0}, stack2[size]={0};

	cout << "\nPush data in stack #1 :\n";
	while(top!=size)
	{
		cout << top+1 << ".   ";
		cin >> stack[top++];
		cout << "\tStack updated!!\n";
	}

	cout << "\nStack #1 is :\n";
	for (int i = 1; i <= top; ++i)
	{
		cout << "  " << i << ". " << stack[i-1] << "\n";
	}

	while(top!=0)
		stack2[top2++] = stack[--top];

	cout << "\nThe reverse-stack (stack#2) is :\n";
	for (int i = 1; i <= top2; ++i)
		cout << "  " << i << ". " << stack2[i-1] << "\n";
	return 0;
}
