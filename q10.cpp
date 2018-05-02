
#include<iostream>
using namespace std;
void swap(int *fir, int *sec)
{
    int temp = *fir;
    *fir = *sec;
    *sec = temp;
}

void permutation(int arr[], int curr, int size)
{
    if(curr == size-1)
    {
        for(int i=0; i<size; i++)
            cout << arr[i] << "\t";
        cout << endl;
    }

    else
    {
        for(int i=curr; i<size; i++)
        {
            swap(&arr[curr], &arr[i]);
            permutation(arr, curr+1, size);
            swap(&arr[curr], &arr[i]);
        }
    }
}

int main()
{ int size;
   cout<<"\nEnter size of set ";
   cin>>size;
   int *a = new int[size];
   for(int i=0;i<size;i++)
   {
   cout<<"\nEnter set elements : ";
   cin>>a[i];
   }

    permutation(a, 0, size);
    return 0;
}
