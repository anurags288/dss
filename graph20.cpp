#include <iostream>
#include <cstdlib>
using namespace std;


int main()

{
    int m,n,l,i;int ch;
    do
    {


    cout<<"Enter the value of m: ";

    cin>>m;
    cout<<"enter 1 for calculating internal nodes and leaf nodes"<<endl;
    cout<<" enter 2 for calculating total nodes and leaf nodes"<<endl;
    cout<<"enter 3 for calculating total nodes and internal nodes"<<endl;
    cout<<"enter 4 to exit"<<endl;

    cin>>ch;
    switch(ch)
    {
        case 1:
        cout<<"enter total vertices";
        cin>>n;
        cout<<"total number of internal nodes = "<<(n-1)/m<<endl;
        cout<<"total number of leaf nodes = "<<((m-1)*n+1)/m;
        break;
        case 2:
        cout<<"enter number of internal vertices";
        cin>>i;
        cout<<"total number of nodes = "<<m*i+1<<endl;
        cout<<"total number of leaf nodes = "<<((m-1)*i+1);
        break;
        case 3:
        cout<<"enter number of leaf nodes";
        cin>>l;
        cout<<"total number of internal nodes = "<<(l-1)/(m-1)<<endl;
        cout<<"total number of nodes = "<<(m*l-1)/(m-1);
        break;
        case 4:
            break;
        default:
        cout<<"wrong choice";
        } cout<<endl<<endl<<endl;
    }
        while(ch!=4);


    return 0;

}
