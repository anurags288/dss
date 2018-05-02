#include<iostream>
using namespace std;

void insertSort(int arr2[],int size)
{
  int comp=0;
 cout<<"THE INTERMEDIATE COMPARISONS RESULT DURING EACH PASS ARE : \n";
 for (int i = 1; i < size; i++)

    {
      for (int j = i; j >= 1; j--)
      {
       if (arr2[j] < arr2[j-1])
        {
         int temp = arr2[j];
         arr2[j] = arr2[j-1];
         arr2[j-1] = temp;
           for(int i=0;i<size;i++)
           cout<<arr2[i]<<" ";
           cout<<endl;
          comp++;
        }
       else
       break;
      }
   }
  cout<<"THE TOTAL NUMBER OF COMPARISONS IS : "<<comp<<'\n';
  return;
}

int main()
{

  int size;
  cout<<"ENTER THE SIZE OF THE ARRAY \n";
  cin>>size;

  int arr[size];
  cout<<"ENTER THE ARRAY ELEMENTS ONE BY ONE.......\n";
  for(int i=0;i<size;i++)
  cin>>arr[i];

  int arr2[size];

  cout<<"THE GIVEN ARRAY IS  : \n";
  for(int i=0;i<size;i++)
  {
   arr2[i] = arr[i];
   cout<<arr[i]<<" ";
  }

  cout<<endl;

  insertSort(arr2,size);
  cout<<"\nTHE SORTED ARRAY IS (BY USING INSERTION SORT) : \n";
   for(int i=0;i<size;i++)
  cout<<arr2[i]<<" ";

  return 0;

}
