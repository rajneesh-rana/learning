#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;
 
// Number of vertices in given graph
#define V 8
 
bool bfs(int graph[][V], int s, int t, int parent[], int visited[])
{

	parent[s]=-1;
	queue<int> Q;
	Q.push(s);

	visited[s]=true;
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		
		for(int i=0;i<V;i++){
			if(!visited[i] && graph[u][i]){
				parent[i]=u;
				visited[i]=true;
				Q.push(i);
			}
		}
	}

	return (visited[t]==true);
}

int findDisjointPaths(int graph[][V],int s, int t)
{
	int parent[V];
	int visited[V];
	
	bool flag=true;
	int max_flow=0;
	while(flag){
	int i,j;
	for(i=0;i<V;i++)
	{
		visited[i]=0;
	}

	flag=bfs(graph,s,t,parent,visited);
	cout<<flag<<endl;
		int minimum=INT_MAX;
	if(flag){
		if(visited[t]){
		
		for(i=t;i!=s;i=parent[i]){
			int j=parent[i];	
			minimum=min(minimum,graph[j][i]);
		}
	
		for(i=t;i!=s;i=parent[i]){
			int j=parent[i];	
			graph[j][i]-=minimum;
			graph[i][j]+=minimum;
		}
		}
		max_flow+=minimum;
		}
	}
	return max_flow;
}

// Driver program to test above functions
int main()
{
    // Let us create a graph shown in the above example
    int graph[V][V] = { {0, 1, 1, 1, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 1, 0},
                        {0, 0, 0, 0, 0, 0, 1, 0},
                        {0, 0, 1, 0, 0, 0, 0, 1},
                        {0, 1, 0, 0, 0, 0, 0, 1},
                        {0, 0, 0, 0, 0, 1, 0, 1},
                        {0, 0, 0, 0, 0, 0, 0, 0}
                      };
 
    int s = 0;
    int t = 7;
    cout << "There can be maximum " << findDisjointPaths(graph, s, t)
         << " edge-disjoint paths from " << s <<" to "<< t<<endl ;
 
    return 0;
}
