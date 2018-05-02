#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX 20
   	int adj[MAX][MAX];
        int n;
class AdjacencyMatrix
{
    private:
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
            int c=0;
            for(i = 0;i < n;i++)
            {
                for(j = 0; j < n; j++)
                    {
                    if(adj[j][j]==0 && adj[i][j]==1)
                        ;
                    else
                            c=1;
                    }
            }
                if(c==0)
                    cout<<"the graph is complete";
                else
                                        cout<<"the graph is incomplete";
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
			           cc=1;
			           cout<<"cannot have self loops"; break;}
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
			  if(cc==0){
            obj.display();}
			break;
			}
			default:
			cout<<"wrong choice";
		}
    return 0;

}
