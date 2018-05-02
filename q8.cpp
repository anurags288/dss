#include <iostream>
using namespace std;
class bubble
{
public:
    void sort(int n[],int limit);
};
void bubble::sort(int n[],int limit)
{
    int i,j,c=0,k,l,temp;
    l=limit;
    //begin sorting
    for (i=0; i<l-1; i++)
    {
        for (j=0; j<l-i-1; j++)
        {
            if (n[j]>n[j+1])
            {
                temp=n[j];
                n[j]=n[j+1];
                n[j+1]=temp;
            }
            c++;
            cout <<"Number of Comparison: " << c << endl;
            cout <<"\nIntermediate Result: \n";
            for(k=0; k<l; k++)
                cout << n[k] <<" ";
            cout << endl;
        }
    }
}//end of function

int main()
{
    int i,limit;
    cout <<"Enter Limit to Array: ";
    cin >> limit;
    cout << endl;
    cout <<"Enter Unsorted Array: ";
    int a [100];
    for (i=0; i<limit; i++)
        cin >> a[i];
    bubble b;
    b.sort(a,limit);
    return 0;
}
