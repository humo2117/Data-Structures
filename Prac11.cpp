/*
	WAP to calculate factorial and to compute the factors of a given no
		(i) using recursion,
		(ii) using iteration.
*/

#include<iostream>
using namespace std;

int factorial(int n)
{
	if(n==1)
		return 1;
	else
		return(n*(factorial(n-1)));
}

void factors(int num, int i)
{
	if(num==i)
	{
		cout << num;
		return;
	}
	if(!(num%i))
		cout << i << " ";
	factors(num,++i);
}

int main()
{
	int num, fact=1;
l1:	cout << "Enter a natural number : ";
	cin >> num;
	if(num<=0)
	{
		cout << "A NATURAL NUMBER ONLY." << endl;
		goto l1;
	}
	for(int i=num; i>0; i--)
		fact*=i;
	cout << "Factorial (using iteration) : " << fact << endl;
	cout << "Factorial (using recursion) : " << factorial(num) << endl << endl;

	cout << "Factors of " << num << " (using iteration) : ";
	for(int i=1;i<=num;i++)
		if(!(num%i))
			cout << i << " ";
	cout << "\n";
	cout << "Factors of " << num << " (using recursion) : ";
	factors(num,1);
	cout << "\n";
	return 0;
}
