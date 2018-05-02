#include<iostream>
using namespace std;
 int n,f=0;

class set
{  int a[10];  public:
  void input(int m)
   { cout<<"\n ENTER no of ELEMENTS(<10) for SET "<<m;
     cin>>n;
int i;
     cout<<"\n Enter Elements (enter 0 to stop) for set "<<m;
     for ( i=1;a[i-1]!=0;i++)
      {cin>>a[i];




      } n = i-2;
      cout<<"\n \t \tCARDINALITY OF THE ABOVE SET IS   "<<n;
   }
   void ismem(int p)
   { for(int i=1; i<=n;i++)
     { if(p==(*this).a[i])
       {f=1; break;
      } }

      if(f==1)
     cout<<"\n YES IS Member";
     else
     cout<<"\n nOt a member";
   }
   void power()
    { for(int i=1;i<=n;i++)
        { for(int j=i ; j<=n;j++)
          cout<<endl<<a[j];
        cout<<a[i]<<endl;}
    }
 void display(int m)
 {cout<<"\n ELEMENTS of set "<<m<<"ARE \n";
   for (int i=0;i<n;i++)
     cout<<" "<<a[i]<<",";
 }
 int card(int m)
  {{ int c=0;
   for( int i=0;i<10;i++)
    {c++;if(a[i]=00)
    break;
    }
    int *p;
    int count=0;

    for(p=a;p<&a+1;p++)
        count++;
    int c= sizeof(a)/sizeof(a[0]);

   return c;
   }
   };

};
int main()
 { set a,b;
   int m;
    a.input(1);
    b.input(2);
    a.ismem(12);
    a.power();
    a.display(1);
    b.display(2);
    do
    { cout<<"\t\t ||| SET OPERATIONS |||";
      cout<<"\n 1. Cardinality \n 2. IS member \n 3. Power SET \n 4. EXIT";
      cin>>m;
      switch(m)
       { case 1: a.card(1);
                 b.card(2); break;
         case 2: cout<<"\n ENTER ELEMENT to be checked";
                 int n;
                 cin>>n;
                 a.check(1,n);
                 b.check(2,n); break;
        case 3:  a.power(1);
                 b.power(2); break;
        case 4:  break;

       }
    } while(m!=4)

    return 0; }
