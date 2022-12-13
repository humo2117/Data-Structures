/*
	WAP to calculate GCD of 2 number
		(i) with recursion
		(ii) without recursion
*/
#include<iostream>
using namespace std;

int GCD(int c, int d, int e)
{
	int k=1;
	e=c%d;

	if(e!=0)
		return (GCD(d,e,k));
	else
		return d;
}

int main(int argc, char const *argv[])
{
	int a, b, gcd=1;
	cout << "Enter a number : ";
	cin >> a;
	cout << "Enter another number : ";
	cin >> b;
	for(int i=1; i<=a && i<=b; i++)
	{
		if(!(a%i) & !(b%i))
			gcd=i;
	}
	cout << "GCD of " << a << " and " << b << " (through iteration) = " << gcd << endl;
	cout << "GCD of " << a << " and " << b << " (through recursion) = " << GCD(a,b,1) << endl;
	return 0;
}
