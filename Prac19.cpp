/*
	WAP to implement Lower Triangular Matrix using one-dimensional array.
*/
#include<iostream>
using namespace std;

int main()
{
	int side=0, array[100];
	cout << "Enter side of square matrix (<=10) : ";
	cin >> side;

	cout << "\nSquare matrix of side " << side << " created";

	cout << "\n\nEnter elements of the matrix :\n";
	for(int i=0, j=1; i<(side*side); i++)
	{
		if(!(i%side))
			cout << "  Row " << j++ << endl;
		cout << "\t";
		cin >> array[i];
//		array[i]=i+1;
	}

	cout << "\nThe matrix :";
	for(int i=0, j=1; i<(side*side); i++)
	{
		if(!(i%side))
			cout << "\n";
		cout << "\t" << array[i];
	}
	cout << "\n";

	cout << "\nLower triangular matrix : ";
	for(int i=0,j=1,k=1; i<(side*side); i++,k++)
	{
		if(!(i%side))
		{
			j++;
			k=1;
			cout << "\n";
		}
		cout << "\t";
		if(j>=(k+1))
			cout << array[i];
		else
			cout << 0;
	}
	cout << "\n";
	return 0;
}
