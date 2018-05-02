#include<iostream>
using namespace std;

int fab(int);

int main()
{
	int ls;

	cout<<"\nEnter number of elements you want to see in the series:";
	cin>>ls;

	for(int i=0;i<ls;i++)
	{
		cout<<fab(i)<<" ";
	}

return 0;

}


int fab(int n)
{
	if(n == 0 || n == 1)
		return n;

	else
		return fab(n-1) + fab(n-2);
}
