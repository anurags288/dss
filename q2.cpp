#include<iostream>
#include<stdlib.h>

using namespace std;

class Set
{
    int a[20],size;
public:
    void subset(Set s);
    void input(int);
    void remove_dup();

    void display();
    void unionn(Set s);
    void intersection(Set s);
    void difference(Set s);
    void symdif(Set s);
    void cartesian(Set s);
    int getsize()
    {
        return size;
    }

};

void Set::  input(int m)
{
    int i,k;
    cout<<"\n Enter Elements (enter 0 to stop) for set  "<<m<<endl;
    cin>>a[0];
    for ( i=1; a[i-1]!=0; i++)
    {
        cin>>a[i];
    }

    size = i-2;
    (*this).remove_dup();
    cout<<"\n \t \tCARDINALITY OF THE ABOVE SET IS   "<<size;
}
void Set::remove_dup()
{
    int c=0;
    for (int i=1; i<=size; i++)
    {
        for (int j=i+1; j<=size;)
        {
            if (a[i]==a[j])
            {
                c=c+1;
                for(int k=j; k<=size-1; k++)
                {
                    a[k]=a[k+1];
                }
                --size;
            }
            else
                ++j;
        }
    }
}
void Set::display()
{
    for(int i=1; i<=size; i++)
    {
        cout<<a[i]<<" ";
    }
}

void Set::subset(Set s)
{
    if(size>=s.getsize())
    {
        int p= getsize();
        int c[p+1];

        for(int i=1; i<=s.getsize(); i++)
            c[i]=0;
        for(int i=1; i<=s.getsize(); i++)
        {
            for(int j=1; j<=size; j++)
            {
                if(s.a[i]==a[j])
                    c[i]=1;
            }
        }
        int t=1;
        for(int i=1; i<=s.getsize(); i++)
        {
            if(c[i]==0)
            {
                cout<<"set 2 is not a subset of set 1"<<endl;
                t=0;
            }
        }
        if(t==1)
            cout<<"set 2 is a subset of set 1"<<endl;

    }
    else
    {
        int c[size+1];
        for(int i=1; i<=size; i++)
            c[i]=0;

        for(int i=1; i<=size; i++)
        {
            for(int j=1; j<=s.getsize(); j++)
            {
                if(s.a[i]==a[j])
                    c[i]=1;
            }
        }
        for(int i=1; i<=size; i++)
        {
            if(c[i]==0)
            {
                cout<<"set 1 is not a subset of set 2"<<endl;
                exit(0);
            }
        }
        cout<<"set 1 is a subset of set 2"<<endl;
    }

}

void Set::unionn(Set s)
{
    int c[50],m[50]= {0},l=1;

    for(int i=1; i<=size; i++)
    {
        for(int j=1; j<=s.getsize(); j++)
        {
            if(a[i]==s.a[j])
                m[j]=-1;

        }
    }

    for(int i=1; i<=size; i++)
    {
        c[i]=a[i];
        l++;
    }

    for(int j=1; j<=s.getsize(); j++)
    {
        if(m[j]==0)
        {
            c[l]=s.a[j];
            l++;
        }
    }
    for(int i=1; i<l; i++)
    {
        cout<<c[i]<<" ";

    }
    cout<<endl;
}


void Set::intersection(Set s)
{
    int c[50],l=1;
    for(int i=1; i<=size; i++)
    {
        for(int j=1; j<=s.getsize(); j++)
        {
            if(a[i]==s.a[j])
            {
                c[l]=a[i];
                l++;
            }
        }
    }
    for(int i=1; i<l; i++)
    {
        cout<<c[i]<<" ";
    }
    cout<<endl;
}

void Set::difference(Set s)
{
    int l=1;
    int m[50],f=0;

    for(int i=1; i<=size; i++)
    {
        f=0;
        for(int j=1; j<=s.getsize(); j++)
        {
            if(a[i]==s.a[j])
                f=1;
        }
        if(f==0)
        {
            m[l]=a[i];
            l++;
        }
    }
    for(int i=1; i<l; i++)
    {
        cout<<m[i]<<" ";
    }
    cout<<endl;

}

void Set::symdif(Set s)
{
    int l=1,k=1;
    int m[50],n[50],f=0;

    for(int i=1; i<=size; i++)
    {
        f=0;
        for(int j=1; j<=s.getsize(); j++)
        {
            if(a[i]==s.a[j])
                f=1;
        }
        if(f==0)
        {
            m[l]=a[i];
            l++;
        }
    }


    for(int i=1; i<=s.getsize(); i++)
    {
        f=0;
        for(int j=1; j<=size; j++)
        {
            if(s.a[i]==a[j])
                f=1;
        }
        if(f==0)
        {
            n[k]=s.a[i];
            k++;
        }
    }


    for(int i=1; i<l; i++)
    {
        cout<<m[i]<<" ";
    }
    for(int i=1; i<
    k; i++)
    {
        cout<<n[i]<<" ";
    }
    cout<<endl;
}

void Set::cartesian(Set s)
{
    cout<<"{ ";
    for(int i=1; i<=size; i++)
    {
        for(int j=1; j<=s.getsize(); j++)
        {
            cout<<"("<<a[i]<<","<<s.a[j]<<"),";
        }
    }
    cout<<" }";
    cout<<endl;
}





int main()
{
    Set s1,s2;
    s1.input(1);
    s2.input(2);
    int ch;
    do
    {
        cout<<"\n1-Subset"<<endl;
        cout<<"2-Display"<<endl;
        cout<<"3-Union"<<endl;
        cout<<"4-Intersection"<<endl;
        cout<<"5-Difference"<<endl;
        cout<<"6-Symmetric Difference"<<endl;
        cout<<"7-Cartesian Product"<<endl;
        cout<<"enter your choice "<<endl;
        cout<<"press 9 to exit "<<endl;
        cin>>ch;

        switch(ch)
        {
        case 1:
            s1.subset(s2);
            break;
        case 2:
            cout<<"set 1"<<endl;
            s1.display();
            cout<<endl<<"set 2"<<endl;
            s2.display();
            //getch();
            break;
        case 3:
            s1.unionn(s2);
            //getch();
            break;
        case 4:
            s1.intersection(s2);
            //getch();
            break;
        case 5:
            s1.difference(s2);
            //getch();
            break;
        case 6:
            s1.symdif(s2);
            break;
        case 7:
            s1.cartesian(s2);
            break;
        case 9:
            break;
        default:
            cout<<"wrong choice..."<<endl;
        }
    }
    while(ch!=9);
    return 0;
}



