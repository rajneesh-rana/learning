#include <stdio.h>
#include <iostream>
using namespace std;

int P[100001];
int C[100001][3];
int R[100001];
int cnt;
void sum(int r){
		if(r==-1)
				return ;
		cnt++;
		sum(C[r][1]);
		sum(C[r][2]);

			return;
}

int main()
{
	freopen("ancestor.txt","r",stdin);
	int tc;
	cin>>tc;
	for(int t=1;t<=tc;t++)
	{
		int N, E, n1, n2;
		cin>>N>>E>>n1>>n2;
		int i,j;
		cnt=0;
		for(i=1;i<=N;i++)
		{
			P[i]=-1;
			C[i][1]=C[i][2]=-1;
			R[i]=-1;
		}
		int t1, t2;
		for(i=1;i<=E;i++)
		{
			cin>>t1>>t2;
			P[t2]=t1;
			if(C[t1][1]==-1)
				C[t1][1]=t2;
			else
				C[t1][2]=t2;
		}
		

		i=n1;
		while(true)
		{
			if(P[i]==-1)
				break;
			else{
				R[P[i]]=1;
				i=P[i];
			}
		}
		i=n2;
		int r;
		while(true)
		{
			if(P[i]==-1)
				break;
			else{
				if(R[P[i]]!=-1){
					r=P[i];
					break;
					}
				i=P[i];
			}
		}
		sum(r);
		cout<<r<<" "<<cnt<<endl;
		}

		return 0;
}
