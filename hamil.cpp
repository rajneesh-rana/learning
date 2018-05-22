#include <iostream>
#include <queue>
#include <stack>
using namespace std;

#define N 5
int V[10];

bool hamutil(int n, bool graph[N][N],stack<int> &Q,int count, int first)
{
	V[n]=true;

	if(count==N){
#if 0
	 for(int i=0;i<N;i++)
		if(!V[i]){
		 V[n]=false;
		 return false;
		}
#endif 
	 if(graph[n][first])
		return true;
	 V[n]=false;
	 return false;
	}

	
	for(int i=0;i<N;i++){
		if(!V[i] && graph[n][i]){
			Q.push(i);
			if(hamutil(i,graph,Q, count+1,first))
				return true;
			Q.pop();
		}

	}

	V[n]=false;
	return false;
}




void hamCycle(bool  graph[][N])
{	
	int i;
	for(i=0;i<=N;i++){
		V[i]=0;
	}
	stack<int> Q;

	for(i=0;i<N;i++){
		Q.push(i);
	 	if(hamutil(i,graph,Q,1,i))
			break;
		Q.pop();
	}

		cout<<"elements"<<endl;
	while(!Q.empty()){
		cout<<" "<<Q.top();
		Q.pop();
	}
	cout<<endl;
}


int main()
{
   /* Let us create the following graph
      (0)--(1)--(2)
       |   / \   |
       |  /   \  |
       | /     \ |
      (3)-------(4)    */
   bool graph1[N][N] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                     };
 
    // Print the solution
    hamCycle(graph1);
 
   /* Let us create the following graph
      (0)--(1)--(2)
       |   / \   |
       |  /   \  |
       | /     \ |
      (3)       (4)    */
    bool graph2[N][N] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 0},
                      {0, 1, 1, 0, 0},
                     };
 
    // Print the solution
    hamCycle(graph2);
 
    return 0;
}
