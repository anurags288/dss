#include <iostream>
#include <sstream>
#include<stdlib.h>
using namespace std;
class relation
{
private:
    int a[30][2];
    int b[50][50];
    int set[];
    int size;
    int l2;
public:
    void input();
    void remove_dup();
    void setmatrix();
    int transitive();
    int reflexive();
    int symmetric();
    int antisymmetric();
};
void relation::  input()
{
    int i;
    cout<<"\n Enter Elements (enter 0 to stop) for set  "<<endl;
    for ( i=1; set[i-1]!=0; i++)
    {
        cin>>set[i];




    }

    size = i-2;
    (*this).remove_dup();
    cout<<"\n \t \tCARDINALITY OF THE ABOVE SET IS   "<<size;
}
void relation::remove_dup()
{
    int c=0;
    for (int i=1; i<=size; i++)
    {
        for (int j=i+1; j<=size;)
        {
            if (set[i]==set[j])
            {
                c=c+1;
                for(int k=j; k<=size-1; k++)
                {
                    set[k]=set[k+1];
                }
                --size;
            }
            else
                ++j;
        }
    }
}
void relation::setmatrix()
{

    int x=0,y,z,f=0,i,j;
    cout << "\n\nEnter Relation Pairs (Press -1 to exit)"<< endl;
    do
    {
        cout<< "Domain: ";
        cin >>y;
        cout << endl;
        a[x][0]=y;//relation
        if (y==-1)
            break;
        else
        {
            cout <<"Range: ";
            cin >> z;
            for (i=1; i<=size; i++)
            {
                if (set[i]==y)
                {
                    for (j=1; j<=size; j++)
                        if (set[j]==z)
                            f=1;
                }
            }
            if (f==1)
            {
                cout << endl;
                a[x][1]=z;
            }
            else
            {
                cout << "Not in set" << endl;
                exit(0);
            }
        }
        f=0;
        int py,pz;
        for(int i=1; i<=size; i++)
        {
            if(set[i]==y)
                py=i;
            if(set[i]==z)
                pz=i;
        }
        b[py][pz]=1;
        x++;
    }
    while(true);
    cout <<"Matrix:"<< endl;
    for(i=1; i<=size; i++)
    {
        cout<<endl<<"\t\t\t\t";
        for(j=1; j<=size; j++)
        {
            cout <<b[i][j] << " ";
        }
    }
}
int relation::transitive()
{
    int t=1;
    int i,j,k;
    for(int i = 1; i<=size; i++)
        for(int j = 1; j<=size; j++)
            for(int k = 1; k<=size; k++)
                if(b[i][j] == 1 && b[j][k] == 1 && b[i][k] != 1)
                    t= 0;

    return t;
}
int relation::reflexive()
{
    int i,j,t=1;
    for(int i = 1; i<=size; i++)
    {
        if(b[i][i] != 1)
        {
            t = 0;
            break;
        }
    }
    return t;
}
int relation::symmetric()
{
    int t=1,i,j;
    for(int i = 1; i<=size; i++)
    {
        for(int j = 1; j<=size; j++)
        {
            if(b[i][j] != b[j][i])
            {
                t = 0;
                break;
            }
        }
    }
    return t;
}
int relation::antisymmetric()
{
    int i,j,t=1,f;
    for(int i = 1; i<=size; i++)
    {
        for(int j = 1; j<=size; j++)
        {
            if(i==j && b[i][j]==1)
            {
                f=0;
            }


            else if(i!=j)
            {
                if(b[i][j] && b[j][i])
                {
                    f=1;
                }


                if(f==1)
                {
                    t=0;
                }
                return t;




            }
        }
    }
    return t;
}
int main()
{
    relation r;
    int a,b,c,d;
    r.input();
    r.setmatrix();
    a=r.transitive();
    cout <<endl<< "\n\n\t\tRESULTS ARE AS FOLLOWS::" << endl;

    if (a==1)
        cout <<endl<< "\t\t->TRANSITIVE" << endl;
    else
        cout <<endl<<"\t\t->NOT TRANSITIVE" << endl;
    b=r.reflexive();
    if (b==1)
        cout << "\t\t->REFLEXIVE" << endl;
    else
        cout << "\t\t->NOT REFLEXIVE" << endl;
    c=r.symmetric();
    if (c==1)
        cout << "\t\t->SYMMETRIC" << endl;
    else
        cout << "\t\t->NOT SYMMETRIC" << endl;
    d=r.antisymmetric();
    if (d==1)
        cout << "\t\t->ANTISYMMETRIC" << endl;
    else
        cout << "\t\t->NOT ANTISYMMETRIC" << endl;
    int h=0;
    if (a==1 && b==1 && c==1)
    {
        cout <<"\t\t->EQUIVALENT"<< endl;
        h++;
    }
    else
        cout <<"\t\t->NOT EQUIVALENT"<< endl;
    if(a==1 && b==1 && d==1)
    {
        cout <<"\t\t->PARTIAL ORDER"<< endl;
        h++;
    }
    else
        cout <<" \t\t->NOT A PARTIAL ORDER"<< endl;
    if (h==0)
        cout <<"\t\t->NONE"<<endl;
    return 0;

}

