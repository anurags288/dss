#include<iostream>
using namespace std;

int BinarySearch(int [], int, int, int);

int main()
{
	int a[20], sa, ele, st, ls;

	cout<<"\nEnter the size of the array you want to see:";
	cin>>sa;

	cout<<"\nEnter the elements of the array.";
	for(int i=0;i<sa;i++)
	{
		cout<<"\nEnter the element number "<<i+1<<":";
		cin>>a[i];
	}

	st = 0;
	ls = sa-1;

	cout<<"\nEnter the element you want to search in the array:";
	cin>>ele;

	int result = BinarySearch(a,st,ls,ele);

	if(result == -1)
		cout<<"\nElement not found.";

	else
		cout<<"\nElement is present at index number "<<result;

return 0;

}


int BinarySearch(int a[], int st, int ls, int ele)
{
	if(st > ls)
	 return -1;

	int mid = (st + ls)/2;

	if(a[mid] == ele)
		return mid;

	else if(a[mid] > ele)
		return BinarySearch(a,st,mid-1,ele);

	else if(a[mid] < ele)
		return BinarySearch(a,mid+1,ls,ele);

	

}
