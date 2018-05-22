#include <iostream>
#include <stdio.h>
using namespace std;


int M[100][100];
int V[100];
int D[100];
int X[100], Y[100];
int N;
#define INT_MAX 999999999
int abs(int x){
	if(x<0)
	 return x*(-1);
	return x;
}

int path(int sum, int cnt, int v){
		if(cnt==N-2){
		//	cout<<"last "<<(sum+M[v][2])<<endl;
			return sum+=M[v][2];
		}

		 V[v]=true;
		 int cost=INT_MAX;
	
		 for(int i=1;i<=N;i++){
			if(i==v)
				continue;
			if(!V[i]){
				int tmp=path(sum+M[v][i],cnt+1,i);
			//	cout<<"P "<<tmp<<" "<<sum<<" "<<cnt<<" "<<v<<" "<<N<<endl;
				if(tmp<cost)
					cost=tmp;
			}
		 }
		 V[v]=false;
		 return cost;
}

int main()
{
	freopen("optimal.txt","r",stdin);
	int tc;
	cin>>tc;
	for(int t=1;t<=tc;t++)
	{
		int i, j;
		cin>>N;
		N=N+2;
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
			M[i][j]=0;

		for(i=1;i<=N;i++){
			cin>>X[i]>>Y[i];			
	  }
		
		for(i=1;i<=N;i++){
			V[i]=0;
			for(j=1;j<=N;j++){
				if(i==j)
					continue;
				M[j][i]=M[i][j]=abs(X[i]-X[j])+abs(Y[i]-Y[j]);
			}
		}

	
		V[2]=true;
		cout<<path(0,0,1)<<endl;
	}
	return 0;
}
