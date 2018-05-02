#include <iostream>
#include<stdlib.h>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;
int size = 0;

int *difference(int a[],int b[],int size1,int size2)
{int *ar3 = new int[100];
int f;
int n3=0;
	 for(int i = 0; i < size1; ++i)
	 {
	 	f = 1;
		for(int j = 0; j < size2; ++j)
		{
			if(a[i] == b[j])
			{
				f = 0;
				break;
			}
		}

		if(f)
		{
			ar3[n3++] = a[i];
		}

	}
	::size = n3;
return ar3;
}


void union0(int a[],int b[],int size1,int size2)
{int *ar3 = new int[200];
int n3 = size2 + size1;
int k=0;
for(int  i = 0; i < size1; ++i)
{
	ar3[i] = a[i];
}

for(int i = size1; i < n3; ++i)
{
	ar3[i] = b[k++];
}


cout<<"\n{";
for(int  i=0;i<n3-1;i++)
cout<<ar3[i]<<",";
cout<<ar3[n3-1];
cout<<"}\n";
return;
}


int *Sorting(int Ar[],int size1)
{
   int temp = 0;
   for(int i = 1;i<size1;i++)
   {
      for(int j = 0;j<size1-i;j++)
      {
         if(Ar[j]>Ar[j+1])
         {
           temp = Ar[j];
           Ar[j] = Ar[j+1];
           Ar[j+1] = temp;
         }
      }
   }
   return Ar;
}
 int *Binary(int n)
    {
        int size1 = ::size;
        int *B = new int[size1];
        for(int i = 0;i<size;i++)
         B[i] = 0;
        int m = size-1;
        while(n>0)
        {
            if(n%2==0)
               B[m--] = 0;
            else
               B[m--] = 1;
            n = n/2;
        }

        for(int i = m;i>=0;i--)
        B[i] = 0;

        return B;
    }

int *Input()
{

   string *S = new string[100];
   int size1 = 0;
   int *A = new int[100];
   do
   {
      cin>>S[size1];
      size1++;
   }while(S[size1 - 1]!= "$");

   size1 = size1 - 1;
   for(int i = 0; i<size1;i++)
   {
      stringstream geek(S[i]);
       geek >> A[i];
   }
   A = Sorting(A,size1);
   ::size = size1;
   return A;
}

int main()
{

      int *A1 = new int[100];
      int *A2 = new int[100];

   int C,size1,size2,f =0;
do{
   cout<<"\n\tWELCOME TO THE MAIN MENU(** Press '$' to End Input**)\n";
   cout<<"Press 1 to Find Cardinality\n";
   cout<<"Press 2 to Check if Sets Are Equivalent\n";
   cout<<"Press 3 to Check if Sets Are Equal\n";
   cout<<"Press 4 to Find Union of Sets\n";
   cout<<"Press 5 to Find Intersection of Sets\n";
   cout<<"Press 6 to Find Cartesian Product\n";
   cout<<"Press 7 to Find Complement or Set Difference Of Sets\n";
   cout<<"Press 8 to Find Power Set\n";
   cout<<"Press 9 to Search Element\n";
   cout<<"Press 10 for Symmetric Difference two sets\n";
   cout<<"Press 11 to check Subset\n";
   cout<<"Press 12 to Exit\n";
   cin>>C;

   if(C==1 || C==8 || C==11)
   {
      cout<<"Enter Set Elements\n";
      A1 = Input();
      size1 = ::size;
      if(C==1)
      cout<<"The Cardinality of The Set is "<<::size;
   }
   if((C>=2 && C<=7) || C==10)
   {

      if(C!=7)
      cout<<"Enter Set One Elements\n";
      else
      cout<<"Enter Universal Set Elements\n";
      A1 = Input();
      size1 = ::size;
      cout<<"Enter Set Two Elements\n";
      A2 = Input();
      size2 = ::size;

   }

   if(C == 2)
   {
      if(size1 == size2)
      cout<<"Sets Are Equivalent";
      else
      cout<<"Sets Are not Equivalent";
   }
   if(C==3)
   {
      if(size1 == size2)
      {
       for(int i = 0;i<size1;i++)
       {
          if(A1[size1] != A2[size1])
          {
              f = 1;
              break;
          }
       }
       if(f == 0)
       cout<<"\nBoth Sets Are Equal";
       else
       cout<<"\nBoth Sets Are Not Equal";
       f = 0;
      }
   }

   if(C == 4 || C==5)
   {

        int *T = new int[size1 + size2];
        int *U = new int[size1 + size2];
        int *I = new int[size1];

        for(int i = 0;i<size1;i++)
        T[i] = A1[i];
        for(int i = 0,j = size1;i<size2;i++,j++)
        T[j] = A2[i];

        int a = 0,b = 0;
        int f1 = 0 ;

        for(int i = 0;i<size1+size2;i++)
        U[i] = 0;

        for(int i = 0;i<size1+size2;i++)
        {
            for(int j = 0;j<a;j++)
            {
                if(T[i]==U[j])
                {
                f1 = 1;
                break;
                }
            }
            if(f1==0)
            {
                U[a] = T[i];
                ++a;
            }
            else
            {
                I[b] = T[i];
                ++b;
            }
            f1=0;
        }

       if(C == 4)
       {
           cout<<"\nThe Union of The Set is \n";
           for(int i = 0;i<a;i++)
           {
              cout<<U[i] <<",";
           }
       }

       if(C==5)
       {
          cout<<"\nThe Intersection of The Set is \n";
          for(int i = 0;i<b;i++)
          {
            cout<<I[i] << ",";
          }
       }
   }

   if(C==6)
   {
       cout<<"\nThe Cartesian Product of the Set is ";
   cout<<"\n{";
   for(int i = 0;i<size1;i++)
   {
      for(int j = 0;j<size2;j++)
      {
          cout<<"("<<A1[i]<<","<<A2[j]<<"),";
      }
   }
   cout<<"}";
   }

   if(C==7)
   {
        int *U = new int[size1 - size2];

   int a = 0;
   int f1 = 0 ;

   for(int i = 0;i<size1;i++)
   U[i] = 0;

   for(int i = 0;i<size1;i++)
   {
       for(int j = 0;j<size2;j++)
       {
       if(A1[i] == A2[j])
       {
          f1= 1;
          break;
       }
       }
       if(f1 == 0)
       {
         U[a] = A1[i];
         ++a;
       }
       f1 = 0;
   }


       cout<<"\nThe Set Difference of The Set is \n";
       for(int i = 0;i<a;i++)
       {
        cout<<U[i] <<",";
       }

  }

  if(C== 8)
  {

        int *Bi = new int[size1];
        for(int i = 0;i<size1;i++)
          Bi[i] = 0;
        cout<<"{ ";
        int po = pow(2,size1);
        for(int i = 0;i<po;i++)
        {
            Bi = Binary(i);
            cout<<"(" ;
            for(int j = 0;j<size1;j++)
            {
                if(Bi[j] == 1)
                {
                    cout<<A1[j]<<" ";
                }
            }
            cout<<"),";
        }
        cout<<("}");
  }


if(C == 9)
{

int srch;
cout<<"Enter set 1 Elements\n";
A1 = Input();
size1 = ::size;
cout<<"Enter Element to search\n";
cin>>srch;
for(int i=0;i<size1;i++)
       {
          if(A1[i] == srch)
          {
              f = 1;
              break;
          }
       }
       if(f == 1)
       cout<<"Element found\n";

}


if (C == 10)
{
int s1,s2;
int *arr1 = new int[100];
int *arr2 = new int[100];
arr1 = difference(A1,A2,size1,size2);
s1 = ::size;
arr2 = difference(A2,A1,size2,size1);
s2 = ::size;
cout<<"Symmetric Difference is :\n";
union0(arr1,arr2,s1,s2);
}



if(C == 11)
{int flag = 0;
size1 = ::size;
//cout<<size1;
cout<<"Enter Subset Elements\n";
A2 = Input();
size2 = ::size;

//cout<<size2;

for(int j = 0;j<size2;j++)
{flag=0;
for(int i = 0;i<size1;i++)
{
if(A2[j]==A1[i])
{
flag=1;
break;
}
}

if(flag == 0)
{cout<<"\nnot a Subset";
exit(1);}}

cout<<"\nValid Subset";}


if(C==12)
{
exit(1);
}
}while(C<13);
}


