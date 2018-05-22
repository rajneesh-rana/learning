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
	 cin>>N;
	 int i, j;
	 
	vector<pair<int, int> > G[N+1];
	map<string,int> M;
	for(i=1;i<=N;i++)
	{
		string s;
		cin>>s;
		M[s]=i;
		cin>>K;
		for(j=1;j<=K;j++){
			int e,w;
			cin>>e>>w;
			G[i].push_back(pair<int,int>(e,w));
		}
	}
	cin>>K;
	
	for(i=1;i<=K;i++)
	{
		string s1,s2;
		int from, to;
		from=M[s1];
		to=M[s2];
		
	}
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
