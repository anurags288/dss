#include<iostream>
#include<cmath>
using namespace std;

int calc(int);

int main()
{
	int degree;

	cout<<"\nEnter the degree of the polynomial:";
	cin>>degree;

	int result = calc(++degree);

	cout<<"\nResult of the polynomial = "<<result;
return 0;

}


int calc(int degree)
{
	int a[degree];

	cout<<"\nEnter the coefficients of the polynomial.";

	for(int i=degree-1;i>=0;i--)
	{
		cout<<"\nEnter the coefficient of degree "<<i<<":";
		cin>>a[i];
	}

	int n,result=0;

	cout<<"\nEnter any number:";
	cin>>n;

	for(int i=degree-1;i>=0;i--)
	{
		result += a[i]*pow(n,i);
	}

	return result;
}
