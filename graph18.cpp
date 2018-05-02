#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX 20
   	int adj[MAX][MAX];

        int n;
        int bdj[MAX][MAX];
        int c[MAX][MAX];
class AdjacencyMatrix
{


    public:

        AdjacencyMatrix(int nin)

        {
		int n=nin;
            for (int i = 0; i < n; i++)

            {


                for(int j = 0; j < n; j++)

                {

                    adj[i][j] = 0;

                }

            }

        }
  void inputedEdge1(int start, int end)

        {

            if( start > n || end > n || start < 0 || end < 0)

            {

                cout<<"Invalid edge!\n";

            }

            else

            {

                adj[start - 1][end - 1] = 1;
                adj[end-1][start-1]=1;

            }

        }


        void inputedEdge(int start, int end)

        {

            if( start > n || end > n || start < 0 || end < 0)

            {

                cout<<"Invalid edge!\n";

            }

            else

            {

                adj[start - 1][end - 1] = 1;

            }

        }

        void display()

        {

            int i,j;

            for(i = 0;i < n;i++)

            {

                for(j = 0; j < n; j++)

                    cout<<adj[i][j]<<"  ";

                cout<<endl;

            }

        }
        void calc(int leng)
        { int i,j,k;
               for(i = 0;i < n;i++)
            {

                for(j = 0; j < n; j++)
                    {
                     bdj[i][j]=adj[i][j];
                    }
            }
            while(leng >1)
            {
                for (i = 0; i <n; i++)
                    {
            for (j = 0; j <n; j++)
                {
                 int sum = 0;
                for (k = 0; k <n; k++)
                {
                sum = sum + adj[i][k] * bdj[k][j];
                }
                    c[i][j] = sum;
                }
                    }
                    leng--;
                    for(i = 0;i < n;i++)
            {

                for(j = 0; j < n; j++)
                    {
                     bdj[i][j]=c[i][j];
                    }
            }

            }
        }


};

int main()

{

    int vertices, max_edges, start, end;
    int len; int cc=0;
    cout<<"Enter number of vertices: ";

    cin>>vertices;
    n=vertices;

    AdjacencyMatrix obj(vertices);
    int ch;
    cout<<"enter 1 for directed graph";
    cout<<"enter 2 for undirected graph";
    cin>>ch;
    switch(ch)
	{
		case 1:
			{
			    max_edges = vertices * (vertices - 1);

			    for (int i = 0; i < max_edges; i++)

    				{

			        cout<<"Enter edge ( negative integers to exit): ";

			        cin>>start>>end;

			        if((start<0) && (end<0))

			            break;
			            if(start==end)

			           {


                        cout<<"cannot have self loops"<<endl;
                        }

                     if(!(start==end))
			        obj.inputedEdge(start, end);

				   }
                if(cc==0)
			    obj.display();
			break;
			}
		case 2:
			{
				max_edges = vertices * (vertices - 1)/2;

			    for (int i = 0; i < max_edges; i++)

    				{

			        cout<<"Enter edge (negative integers to exit): ";

			        cin>>start>>end;

			        if((start <0) && (end<0))

			          {

			           break;}
                    if(adj[end-1][start-1]==1)

			           {

			            cout<<"undirected graph cannot accept value. Try again!"<<endl;
			              }
			            if(start==end)

			           {


                        cout<<"cannot have self loops"<<endl;
                        }


                     if(!(start==end))
			        obj.inputedEdge1(start, end);

				   }
                if(cc==0)
			    obj.display();
			break;
			}
			default:
			cout<<"wrong choice";
		}
		if(!(start>0&& end>>0)){
		cout<<"enter the length of the path  ";
		cin>>len;
		obj.calc(len);
		cout<<" enter starting point  ";
		cin>>start;
		cout<<"enter end point  ";
		cin>>end;
		 int i,j;

            for(i = 0;i < n;i++)
            {

                for(j = 0; j < n; j++)

                    cout<<c[i][j]<<"  ";

                cout<<endl;
            }
            cout<<" number of path available:  "<<c[start-1][end-1];}
    return 0;


}
