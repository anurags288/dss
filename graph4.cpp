#include<iostream>
using namespace std;
#define max 10
class graph
{
    int a[max][max];
    int b[max][max];
    int size;
public:
    graph()
    {
        for (int i=0; i<max; i++)
            for(int j=0; j<max; j++)
                a[i][j]=0;
        size=0;
    }

    void definegraph()
    {
        int t,x,y;
        cout<<"\n Enter the type of Graph \n\n \t 1. Directed \t\t 2. Undirected";
        cin>>t;
        cout<<"\n\n Enter no. of Vertices";
        cin>>size;
        cout<<"\n \t Defining Graph \n Enter First vertex";
        cin>>x;
        cout<<"\n Enter second vertex";
        cin>>y;
        while(x!=-1&&y!=-1&&x-1<size&&y-1<size&&x>0&&y>0)
        {
            a[x-1][y-1]=1;
            if(t==2)
                a[y-1][x-1]=1;
            cout<<"\n Enter First vertex";
            cin>>x;
            cout<<"\n Enter second vertex";
            cin>>y;
        }
        for (int i=0; i<size; i++)
        {
            for(int j=0; j<size; j++)
                b[i][j]=a[i][j];
        }
        euler(t);

    }
    void display()
    {
        cout<<"\nMatrix of your graph is as follows::\n\n\n\t";
        for (int i=0; i<size; i++)
        {
            cout<<endl;

            for(int j=0; j<size; j++)
                cout<<" "<<a[i][j];
        }
    }
    void euler(int t)
    {
        int c[max];
        int s=0,n=0;
        cout<<"/n Enter Set of Vertices(path) -1 to stop";
        cin>>n;
        while(n!=-1)
        {

            c[s++]=n;
            cin>>n;
        }
        bool f=true;
        /*for(int i=0; i<s-1; i++)
        {
            if(b[c[i]-1][c[i+1]-1]==0)
                f=false;
            else
            {
                b[c[i]-1][c[i+1]-1]=0;
                if(t==2)
                    b[c[i+1]-1][c[i]-1]=0;
            }
        } */
        for(int i=0; i<s-1; ++i)
        {
            if(b[c[i]-1][c[i+1]-1]!=1)
                f=false;
            else
            {
                b[c[i]-1][c[i+1]-1]=0;
                if(t==2)
                    b[c[i+1]-1][c[i]-1]=0;
            }
        }
        cout<<f;
        if(s<size)
            f=false;
        else
            for(int i=0; i<s; i++)
                for (int j=i+1; j<s; j++)
                    if((c[i]==c[j])&&(i!=0&&j!=s-1))
                        f=false;
        if(f)
        {
            if(c[0]==c[s-1])
                cout<<"\n\n\tHamiltonian Circuit";
            else
                cout<<"\n\n\tHamiltonian Path";
        }
        else
            cout<<"\n\n\tNot an Hamiltonian Path";
    }

};


int main()
{
    graph g;
    g.definegraph();
    g.display();
}
