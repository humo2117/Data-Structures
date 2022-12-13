/*
	WAP to convert the Sparse Matrix into non-zero form and vice-versa.
*/
#include<iostream>
using namespace std;

int main()
{
	int column=0, row=0, nz=0, matrix[10][10]={0}, nonZero[10][3]={0};
	cout << "Sparse matrix to non-zero form\n\nEnter dimensions of the matrix\n   Columns = ";
	cin >> column;
	cout << "   Rows = ";
	cin >> row;

	cout << "\nEnter data of the matrix";
	for(int i=0; i<row; i++)
	{
		cout << "\n   Row " << i+1 << " :\n";
		for(int j=0; j<column; j++)
		{
l1:			cout << "\t";
			cin >> matrix[i][j];
			if(matrix[i][j]!=0)
				nz++;
			if(nz>((row*column)/2) && matrix[i][j]!=0)
			{
				cout << "\nToo many non-zero elements\nNot forming a sparse matrix.\nEnter all the rest elements equal to 0\n";
				goto l1;
			}
		}
	}

	cout << "\nSparse matrix\n";
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<column; j++)
			cout << "\t" << matrix[i][j];
		cout << "\n";
	}

	for(int i=0, k=0; i<row; i++)
	{
		for(int j=0; j<column; j++)
			if(matrix[i][j]!=0)
			{
				nonZero[k][0] = matrix[i][j];
				nonZero[k][1] = i+1;
				nonZero[k++][2] = j+1;
			}
	}

	cout << "\nThe non-zero form of above sparse matrix :";
	cout << "\n\tData\tRow\tColumn\n";
	int k=0;
	while(nonZero[k][0]!=0)
	{
		cout << "\t" << nonZero[k][0] << "\t" << nonZero[k][1] << "\t" << nonZero[k++][2] << endl;
	}
	cout << "\n";

/************************************************************************************************************/

	int Column=0, Row=0, NZ=0, Matrix[10][10]={0}, NonZero[10][3]={0};
	for(int i=0; i<80; i++)
		cout << "-";
	cout << "\n\nNon-zero form to sparse matrix\n\nEnter dimensions of the matrix\n   Columns = ";
	cin >> Column;
	cout << "   Rows = ";
	cin >> Row;

	int size=0;
	cout << "\nEnter non-zero elements of the matrix";
	while(NZ<((Row*Column)/2))
	{
		size++;
		cout << "\n" << size << ".\n";
L1:		cout << "  Enter data\t:   ";
		cin >> NonZero[size][0];
		if(NonZero[size][0]==0)
		{
			cout << "\nEnter non-zero element only\n";
			goto L1;
		}
		NZ++;
L2:		cout << "  Row\t\t:   ";
		cin >> NonZero[size][1];
		if(NonZero[size][1]>Row)
		{
			cout << "\nMore than row-limit\n";
			goto L2;
		}
		else if(NonZero[size][1]<=0)
		{
			cout << "\nNot less than 0\n";
			goto L2;
		}
L3:		cout << "  Column\t:   ";
		cin >> NonZero[size][2];
		if(NonZero[size][2]>Column)
		{
			cout << "\nMore than column-limit\n";
			goto L3;
		}
		else if(NonZero[size][2]<=0)
		{
			cout << "\nNot less than 0\n";
			goto L3;
		}

		cout << "\nEnter more elements yes(1) or no(0)";
		cin >> k;
		if(k==0)
			break;
	}

	int r1, c1;
	for(int i=0; i<size; i++)
	{
		r1 = NonZero[i][1];
		c1 = NonZero[i][2];
		Matrix[r1-1][c1-1] = NonZero[i][0];
	}


	cout << "\nSparse matrix\n";
	for(int i=0; i<Row; i++)
	{
		for(int j=0; j<Column; j++)
			cout << "\t" << Matrix[i][j];
		cout << "\n";
	}
	return 0;
}
