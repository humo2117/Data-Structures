/*
	WAP using templates to sort a list of elements.
	Give user the option to perform sorting using Insertion sort, Bubble sort or Selection sort
*/
#include<iostream>
using namespace std;

template <class T>
void printArray(T arr[], int n)
{
	for(int i=0; i<n; i++)
	cout << arr[i] << " ";
	cout << "\n";
}

template <class T>
void bubbleSort(T arr[], int n)
{
	for (int i=n-1; i>=0; i--)
	{
		for (int j=0; j<=i-1; j++)
		{
			if (arr[j]>arr[j+1])
			swap(arr[j], arr[j+1]);
			printArray(arr,n);
		}
	}
}

template <class T>
void insertionSort(T arr[], int n)
{
	for (int i=1; i<n; i++)
	{
		int temp = arr[i];
		int j;
		for (j = i; j>0; j--)
		{
			if (arr[j-1] < temp)
				break;
			printArray(arr,n);
			arr[j] = arr[j-1];
			printArray(arr,n);
		}
		arr[j] = temp;
			printArray(arr,n);
	}
}

template <class T>
void selectionSort(T arr[], int n)
{
	for (int i=0; i<n-1; i++)
	{
		int min = i;
		for (int j=i+1; j<n; j++)
		{
			if (arr[j]<arr[min])
			min = j;
		}
		printArray(arr,n);
		swap(arr[i], arr[min]);
	}
}

int main()
{
	int array[50];
	int size=0, option=-1;
	cout << "Enter array size = ";
	cin >> size;
	cout << "\nEnter array values : \n";
	for(int i=0; i<size; i++)
	{
		cout << "\t";
		cin >> array[i];
	}
	printArray(array,size);

	cout << "\nChoose one - Bubble sort(0) / Insertion sort(1) / Selection sort(2) : ";
	cin >> option;
	option%=3;

	if(option==0)
	{
		cout << "\nBubble sort : \n";
		bubbleSort(array,size);
		cout << "\nFinal answer : ";
		printArray(array,size);
	}
	else if(option==1)
	{
		cout << "\nInsertion sort : \n";
		insertionSort(array,size);
		cout << "\nFinal answer : ";
		printArray(array,size);
	}
	else if(option==2)
	{
		cout << "\nSelection sort : \n";
		selectionSort(array,size);
		cout << "\nFinal answer : ";
		printArray(array,size);
	}
	else
		return 404;
	return 0;
}
