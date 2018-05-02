#include<iostream>
#include<stdlib.h>
using namespace std;
class Relation
{
public:
bool reflexive(int **a,int m);
bool symmetric(int **a,int m);
bool transitive(int **a,int m);
bool anti_symmetric(int **a,int m);
 };

bool Relation :: symmetric(int **a,int m)
 {
 int flag=0;
 for(int i=0;i<m;i++)
 for(int j=0;j<m/2;j++)
 {
 if(a[i][j]==1 && a[j][i]==1)
 flag=0;
 else flag=1;
}
return flag;
}


bool Relation :: anti_symmetric(int **a, int m)
{
int flag =0;
for (int i=0;i<m;i++)
for (int j=0;j<m;j++)
{
if(i=j)
{
if(a[i][i]==1)
flag=1;
}
else flag=0;
}
return flag;
}

bool Relation :: transitive(int **a,int m)
{
int flag=0;
for(int i=0;i<m;i++)
for(int j=0;j<m;j++)
for(int k=0;k<m;k++)
{if(a[i][j]==a[i][k] && a[i][k]==a[i][j])
flag=1;
else flag=0;
}
return flag;
}



bool Relation :: reflexive(int **a,int m)
{
int flag=0;
for(int i=0;i<m;i++)
for(int j=0;j<m;j++)
{
if(a[i][i]==1)
flag=1;
else flag=0;
}
return flag;
}


int main()
{
int m;
int flag=0,flag2=0;
int size1=0,a1=0,a2=0,ith_index=0,jth_index=0;

cout<<"\nEnter the size of the set ";
cin>>m;
if(m==0)
{cout<<"Error";exit(0);}

int **arr1;
arr1 = new int*[m];
for(int i = 0;i<m;i++)
arr1[i] = new int[m];
int *a = new int[m];
cout<<"Enter the elements of set "<<endl;
for(int i=0;i<m;i++)
cin>>a[i];
while(true)
{
cout<<"Enter the Related elements(Enter -1 to stop)"<<endl;
cout<<"Enter element  ";
cin>>a1;
if(a1==-1)
break;
cout<<"... related to...";
cin>>a2;
for(int i=0;i<m;i++)
{
if(a1==a[i])
{ flag=1;
ith_index=i;
}}
if(flag=0) {
cout<<"Element not found";exit(0);}

for(int i=0;i<m;i++){
if(a2==a[i])
{flag2=1;
jth_index=i;
}}
if(flag2=0) {
cout<<"Element not found";exit(0);}

arr1[ith_index][jth_index]=1;
}

cout<<"Your relation matrix is :"<<endl;
for(int i=0;i<m;i++)
{
for(int j=0;j<m;j++)
{

    cout<<arr1[i][j]<<" ";
    if(j==m-1)
    cout<<endl;
}
}

Relation R1;
int equivalence=0;
int partial_order=0;

bool r1 = R1.reflexive(arr1,m);
bool s1 = R1.symmetric(arr1,m);
bool tr1 =R1.transitive(arr1,m);
bool ans1 = R1.anti_symmetric(arr1,m);

if(r1)
cout<<"\nReflexive";
if(s1)
cout<<"\nSymmetric";
if(tr1)
cout<<"\nTransitive";
if(ans1)
cout<<"\nAnti-Symmetric";

if(r1 && s1 && tr1 )
{
equivalence=1;
cout<<"\nRelation is equivalence"<<endl;
}
else
cout<<"\nRelation is not equivalence"<<endl;


if(r1 && ans1 && tr1)
{
partial_order=1;
cout<<"\nRelation is partial order relation"<<endl;
}
else
cout<<"\nRelation is not partial order relation"<<endl;

if(equivalence==0 && partial_order==0)
cout<<"\nThe given relation is neither equivalence nor partial order "<<endl;
return 0;


}
