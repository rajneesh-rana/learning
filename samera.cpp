    #include <cctype>
    #include <cstdio>
    #include <cstring>
    #include <queue>
    #include <vector>
	#include <iostream>
    #define NN 501
    #define INF 1061109567
	#include <stack>
    using namespace std;
    int N, E;
	int G[NN][NN];
	int D[NN];
	int V[NN];
	vector <vector <int> > A(NN);
	int s, d;
	
	int min(){
		int index=0;
		int mn=INF+1;
		for(int i=0;i<N;i++){
			if(!V[i] && mn>D[i]){
				mn=D[i];
				index=i;
			}
		}
		return index;
	}

	void DJ(int src){
	D[src]=0;
	int i, j;
	for(i=0;i<N;i++){
		int u=min();
		V[u]=true;
		for(j=0;j<N;j++){
		if(!V[j] && G[u][j] && D[j]>D[u]+G[u][j]){
			int temp=D[u]+G[u][j];
			if(D[j]==INF){
			D[j]=temp;
			A[j].push_back(u);
			}
			else{
			D[j]=temp;
			A[j].clear();
			A[j].push_back(u);	
			}
			//cout<<"=="<<u<<" "<<j<<" "<<G[u][j]<<endl;
		}
		}
	}
	}	

	bool dfs(int dest, stack<int> &S){
	//	cout<<dest<<endl;
		V[dest]=true;
		S.push(dest);
		if(dest==s){
			return true;
		}
		
		for(int i=0;i<A[dest].size();i++){
			if(!V[A[dest][i]] ){
				if(dfs(A[dest][i],S))
					return true;
			}
		}

		S.pop();
		V[d]=false;
	}
	
int main()
{

	freopen("samera.txt","r",stdin);
	while(true){
	cin>>N>>E;
	if(N && E){	
	cin>>s>>d;
	int i, j;

	for(i=0;i<N;i++){
		D[i]=INF;
		V[i]=0;
		A[i].clear();
		for(j=0;j<N;j++)
		{
			G[i][j]=0;
		}
	}
	
	for(i=0;i<E;i++){
		int e1, e2,w;
		cin>>e1>>e2>>w;
		G[e1][e2]=w;
	}

	DJ(s);
	if(D[d]==INF){ cout<<"-1"<<endl; continue;}
	//else
	///	cout<<"path1"<<D[d]<<endl;

	int previous=D[d];


	while(true){
	stack<int> S;
	for(i=0;i<N;i++) 
		V[i]=0;
	dfs(d, S);

	int first=S.top();
	S.pop();
	while(!S.empty())
	{
		int next=S.top();
	//	cout<<first<<"-"<<next<<endl;
		G[first][next]=0;
		first=next;
		S.pop();
	}
 
	#if 1
	for(i=0;i<N;i++){
		D[i]=INF;
		V[i]=0;
		A[i].clear();
	}
	DJ(s);
	if(D[d]==INF){ cout<<"-1"<<endl;break;}
	else{
		if(D[d]==previous)
			continue;
		else{
			cout<<D[d]<<endl;
			break;
			}
	}
	#endif
	}
	}
	else
	 break;

	}
} 
