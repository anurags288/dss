#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX 20
int adj[MAX][MAX];
int n;
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
                cout<<"outdegree of vertex "<<(i+1)<<"  =  "<<sum<<"  ";
                cout<<"indegree of vertex "<<(i+1)<<"  =  "<<sumt;


                cout<<endl;

            }



        }

};

int main()

{
    int cc=0;
    int vertices, max_edges, start, end;

    cout<<"Enter number of vertices: ";

    cin>>vertices;
    n=vertices;

    AdjacencyMatrix obj(vertices);


			    max_edges = vertices * (vertices - 1);

			    for (int i = 0; i < max_edges; i++)

    				{

			        cout<<"Enter edge( negative integers to exit): ";

			        cin>>start>>end;

			        if((start<0) && (end<0))

			            break;
			            if(start==end)
			           {
			            cc=1;
                        cout<<"cannot have self loops";
                        break;
                        }

			        obj.inputedEdge(start, end);

				   }
                    if(!(start >n || end >n) && cc==0)

			    obj.display();




    return 0;

}
