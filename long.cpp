#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
int N, K, S, E;
vector<int> l[2001];
int V[2001];
int MAX;
int dfs(int s,int cnt){

	V[s]=1;
	if(s==E){
	  V[s]=0;
		return cnt;}

	int i;
	int max=-1, tmp;
	for(i=0;i<l[s].size();i++){
		if(!V[l[s][i]]){
		//	V[l[s][i]]=1;
		tmp=dfs(l[s][i], cnt+1);
		if(tmp>max)
			max=tmp;
		}
	}
	V[s]=0;
	return max;
	
}
int print(int s, int max){
	V[s]=1;
	if(max==0 && s==E){
		cout<<E<<" ";
		return 0;
	}
	int i;

	for(i=0;i<l[s].size();i++){
		if(!V[l[s][i]]){
		int tmp=print(l[s][i],max-1);
		if(tmp==0){
			cout<<l[s][i]<<" ";
			return 0;
		}
		}

		
	}
	V[s]=0;
	return max;	
	
}

int main() {
	
	// your code here
	freopen("test","r",stdin);
	cin>>N>>K>>S>>E;
	
	int i, j;
	
	
	int e1, e2;
	for(i=0;i<K;i++)
	{	
		cin>>e1>>e2;
		l[e2].push_back(e1);
		l[e1].push_back(e2);
	}
	int max=dfs(S,0);

	for(i =0;i<=N;i++){
		V[i]=0;
	}
	cout<<S<<" ";
	print(S,max);
	cout<<endl;
	
	return 0;
}
