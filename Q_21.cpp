#include<iostream>
#include<cstdlib>
using namespace std;
void Degree(int mat[][10],int a)
{
	int n,i,j,p=0,c=0,start=0,last=0,ver=0;
	int O[10],I[10];
	for(i=0;i<a;i++)
	{	n=0;
		for(j=0;j<a;j++)
		{	if(mat[i][j]==1)
			{
				n++;
			}
		}
	O[i]=n;
	}
	//Out Degree
	cout<<"Out-Degree\n";
	for(i=0;i<a;i++)
	{
		cout<<i+1<<" = "<<O[i]<<"\n";
	}
	for(i=0;i<a;i++)
	{	n=0;
		for(j=0;j<a;j++)
		{	if(mat[j][i]==1)
			{	
				n++;
			}
		}
	I[i]=n;
	}
	//In Degree
	cout<<"In-Degree\n";
	for(i=0;i<a;i++)
	{
		cout<<i+1<<" = "<<O[i]<<"\n";
	}
	//conditions
	for(i=0;i<a;i++)
	{
		if(O[i]==1&&I[i]==1)
		{	
			c++;
		}
	}
	if(c==a)
	{
		cout<<"\n The Given Graph is a Hamiltonia circuit\n";
		exit(0);
	}
	for(i=0;i<a;i++)
	{
		if(O[i]==1&&I[i]==0)
		{
			start++;
		}
		else if(O[i]==0&&I[i]==1)
		{
			last++;
		}
		else if(O[i]==1&&I[i]==1)
		{	
			ver++;
		}
	}
	if(start==1&&last==1)
	{	
		if(ver==(a-2))
		{
			cout<<"\n Given graph is a Hamiltonian path\n ";
			exit(0);
		}
	}
	cout<<"\n The Given Graph is neither a Hamiltonian path nor Hamiltonian Circuit\n";
}

int main()
{
	int i,j,a,mat[10][10],I,J,A[10];
	char ch,q,c;
	cout<<"\n Enter the number of vertex :";
	cin>>a;
	cout<<"\n Name the vertices :";
	for(i=0;i<a;i++)
	cin>>A[i];
	for(i=0;i<a;i++)
	{	for(j=0;j<a;j++)
		{	
			mat[i][j]=0;
		}
	}
		
	do{
		cout<<"\n Enter the Edge = ";
		cin>>I>>J;
		
		mat[I-1][J-1]=1;
		
		cout<<"\n Do You want to enter more edge(y/n)? ";
		cin>>ch;
		
	   }while(ch=='y'||ch=='Y');
	for(i=0;i<a;i++)
	{	for(j=0;j<a;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	Degree(mat,a);	
return 0;
}
	 
