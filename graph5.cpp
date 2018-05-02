#include<iostream>
using namespace std;
class Tree
{
private:
    int m;
public:
    void internalN(int i)
    {
        cout<<"\nNo of nodes:"<<m*i+1;

        cout<<"\nNo of leaves:"<<i*(m-1)+1;
    }
    void nodes(int n)
    {
        cout<<"\nNo of internal nodes:"<<(n-1)/m;
        cout<<"\nNo of leaves:"<<(n*(m-1)+1)/m;
    }
    void leaves(int l)
    {
        cout<<"\nNo of nodes:"<<(m*l-1)/(m-1);
        cout<<"\nNo of internal nodes:"<<(l-1)/(m-1);
    }
    void input()
    {
        int k;
        int n=3;
        do
        {
            cout<<"\n\n\t\t\t\t||OPERATIONS||\n\n\t\t1) Node\n\t\t2) Leaves\n\t\t3) Internal Nodes\n\t\t4) Exit\n\n\n\t\t\t\tEnter your choice:";
            int ch;
            cin>>ch;

            switch(ch)
            {
            case 1:
                cout<<"\nEnter the value of m:";
                cin>>m;
                cout<<"\nEnter the number of nodes:";
                cin>>k;
                if(k<=0||m<0||k>1&&k<m+1)
                    cout<<"\nWrong input";
                else
                    nodes(k);
                break;
            case 2:
                cout<<"\nEnter the value of m:";
                cin>>m;
                cout<<"\nEnter the number of leaves:";
                cin>>k;
                if(k==0)
                    cout<<"\nNumber of nodes=1";
                else if(k<0||m<0||k>0&&k<m||k%(m-1)!=m-2)
                    cout<<"\nWrong input";

                else
                    leaves(k);
                break;
            case 3:
                cout<<"\nEnter the value of m:";
                cin>>m;
                cout<<"\nEnter the number of internal nodes:";
                cin>>k;
                if(k<0||m<0)
                    cout<<"\nWrong input";
                else
                    internalN(k);
                break;
            case 4:
                n=0;
                break;
            default:
                cout<<"\nWrong choice entered:";
            }
        }
        while(n!=0);

    }

};
int main()
{
    Tree t;
    t.input();
}

