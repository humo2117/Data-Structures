/*
	Write a program to search an element from a list.
	Give user the option to perform Linear or Binary search. Use Template functions
*/
#include<iostream>
using namespace std;

template <class T>
void sort(T a[], int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<i; j++)
		{
			if(a[i]<a[j])
			swap(a[i],a[j]);
		}
	}
}

template <class T>
int linearSearch(T a[], int n, int x)
{
	int pos=0;
	bool found = false;
	for(;pos<n;pos++)
	{
		if(a[pos]==x)
		{
			found = true;
			break;
		}
	}
	if(found)
		return pos;
	else
		return -1;
}

template <class T>
int binarySearch(T arr[], int low, int high, int x)
{
	if (high>=low)
	{
		int mid = low + (high - low)/2;

		if (arr[mid] == x)
			return mid;

		if (arr[mid] > x)
			return binarySearch(arr, low, mid-1, x);

		return binarySearch(arr, mid+1, high, x);
	}
	return -1;
}

int main()
{
	int array[50], size=0, search, option=-1, result=-1;
	cout << "Enter array size = ";
	cin >> size;
	cout << "\nEnter array values : \n";
	for(int i=0; i<size; i++)
	{
		cout << "\t";
		cin >> array[i];
	}
	for(int i=0; i<size; i++)
		cout << array[i] << " ";

	cout << "\nSorting...\n";
	sort(array,size);
	for(int i=0; i<size; i++)
		cout << array[i] << " ";

	cout << "\nSearch = ";
	cin >> search;

	cout << "\nBinary search(0) or Linear search(1) : ";
	cin >> option;
	option%=2;
	if(option)
		(result=linearSearch(array,size,search))>=0 ? cout << "\nLinear Search\n\t" << search << " found at index : " << result << endl : cout << "\nLinear Search\n\t" << search << " not found" << endl;
	else
		(result=binarySearch(array,0,size,search))>=0 ? cout << "\nBinary Search\n\t" << search << " found at index : " << result << endl : cout << "\nBinary Search\n\t" << search << " not found" << endl;
	return 0;
}
