#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX 20
int adj[MAX][MAX];
int n;int a[50]={0};
class AdjacencyMatrix
{


    public:

        AdjacencyMatrix(int n)

        {

            for (int i = 0; i < n; i++)

            {


                for(int j = 0; j < n; j++)

                {

                    adj[i][j] = 0;

                }

            }

        }



        void inputedEdge(int start, int end)

        {if( start > n || end > n || start < 0 || end < 0)

            {

                cout<<"Invalid edge!\n";

            }

            else

            {

                adj[start - 1][end - 1] = 1;
                if(start!=end)
                adj[end-1][start-1]=1;

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
              for(i = 0;i < n;i++)

            {
                    int sum=0;int sumt=0 ;
                for(j = 0; j < n; j++)
                {
                    if(adj[i][j]>0)
                    {
                        sum=sum+adj[i][j];
                    }
                    if(adj[j][i]>0)
                    {
                        sumt=sumt+adj[j][i];
                    }
                }
                cout<<"degree of vertex "<<(i+1)<<"  =  "<<sum<<"  ";
               // cout<<"indegree of vertex "<<(i+1)<<"  =  "<<sumt;
                a[i+1]=sum;

                cout<<endl;

            }



        }

};

int main()

{

    int vertices, max_edges, start, end;

    cout<<"Enter number of vertices: ";

    cin>>vertices;
    n=vertices;

    AdjacencyMatrix obj(vertices);


			    max_edges = vertices * (vertices - 1)/2;

			    for (int i = 0; i < max_edges; i++)

    				{
			        cout<<"Enter edge( negative integers to exit): ";
			        cin>>start>>end;

			        if((start<0) && (end<0))

			            break;
			              if(start==end)

			           {

                        cout<<"cannot have self loops"<<endl;
                      }
                       if(adj[end-1][start-1]==1)

			           {


			            cout<<"undirected graph cannot accept value. Try again!"<<endl;
			              }


                     if(!(start==end))
			        obj.inputedEdge(start, end);

				   }
                    if(!(start >n || end >n) )

			    obj.display();


			    int c=0;
                int y=0;
                for(int i=1;i<(n+1);i++)
                {
                    if(a[i]%2==0)
                        c++;
                    else
                        y++;
                }
            if(c==n)
                cout<<" it is a euler circuit";
            if(y==2)
                cout<<" it is a euler path";
            if(c!=n && y!=2)
                cout<<"it is not a euler path or circuit";


    return 0;

}
