#include <iostream>
#include<cmath>
#include <cstdlib>
using namespace std;


int main()
{
        int size;int c = 11,v3;


        cout<<"Enter the total number of summations required : ";
        cin>>size;

        int *A = new int[size];

        while(c>10)
        {
        cout<<"\nEnter a positive integer constant C (Less than 11) ";
        cin>>c;
        if(c>10)
         cout<<"You Have Entered The Wrong Value;Kindly Try Again.\n";
        }

        int c1 = c;
        for(int i = 1;i<11;i++)
        {
           c = c1;
        for(int i = 0;i<size-1;i++)
        {
          v3 = rand() % c;
          c = c - v3;
          cout<<v3<<"+";
        }
          cout<<c<<" = "<<c1;
        cout<<endl;
        }
        }

