#include<iostream>
using namespace std;

int fact(int);

int main()
{
	int n,r;

	cout<<"\nEnter the value of n:";
	cin>>n;

	cout<<"\nEnter the value of r:";
	cin>>r;

	if(n >=r)
	{
	int c = fact(n)/(fact(r)*fact(n-r));

	cout<<"\nCombination="<<c;

	int p = fact(n)/fact(n-r);

	cout<<"\nPermutation = "<<p;
	}

	else
	{
		cout<<"\nPermutation and Combination is not possible.";
	}
return 0;

}


int fact(int a)
{
	int f=1;

	for(int i=2;i<=a;i++)
	{
		f *= i;
	}

	return f;

}	
