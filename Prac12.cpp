/*
	WAP to display fibonacci series
		 (i) using recursion
		(ii) using iteration.
*/
#include<iostream>
using namespace std;

void fibb(int n)
{
	static int A=1, B=1, C;
	if(n>0)
	{
		C = A+B;
		cout << C << " ";
		swap(A,B);
		swap(B,C);
		fibb(n-1);
	}
}

int main(int argc, char const *argv[])
{
	int n, a=0, b=1, c=1;
	cout << "Enter number of terms : ";
l1:	cin >> n;
	if(n>=1)
	{
		cout << "Fibbonicci series (using iteration) : 1 ";
		for(int i=1; i<n; i++)
		{
			c=a+b;
			cout << c << " ";
			swap(a,b);
			swap(b,c);
		}
		cout << "\nFibbonicci series (using iteration) : 1 ";
		if(n>=2)
			cout << "1 ";
		fibb(n-2);
		cout << "\n";
	}
	else
	{
		cout << "\nEnter a valid number : ";
		goto l1;
	}
	return 0;
}
