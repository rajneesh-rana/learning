#include<vector>
#include<iostream>
#include <climits>
#include <stdio.h>
using namespace std;

int min(int D[], int V[],int N)
{
	int v;
	int index=INT_MAX;
	int dis=INT_MAX;
	for(v=1;v<=N;v++)
	{
		if(!V[v] && D[v]<dis){
			dis=D[v]; index=v;
		}
	}
	return index;
}
int DJ()
{
	 int N, K;
	 cin>>N>>K;
	 int i, j;
	 vector<pair<int, int> > G[N+1];
		int from, to , w;
	for(i=1;i<=K;i++)
	{
		cin>>from>>to>>w;
		G[from].push_back(pair<int,int>(to,w));
	}
	cin>>from>>to;
	int D[N+1];
	int V[N+1];
	for(i=0;i<=N;i++){
		D[i]=INT_MAX;
		V[i]=false;
		}
	D[from]=0;

	for(i=1;i<=N;i++)
	{
		int u=min(D,V,N);
		if(u==INT_MAX)
				break;
		V[u]=true;
	
		for(j=0;j<G[u].size();j++){
			if(!V[G[u][j].first] && D[G[u][j].first]> (D[u]+G[u][j].second))
				D[G[u][j].first]=D[u]+G[u][j].second;
		}	
	}
	
	if(D[to]==INT_MAX)
		cout<<"NO"<<endl;
	else
		cout<<D[to]<<endl;

}

int main()
{
	freopen("dj.txt","r",stdin);
	int t;
	cin>>t;
	while(t--){
	DJ();
	}

	return 0;
}
