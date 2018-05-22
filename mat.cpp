#include<stdio.h>
#include<limits.h>
#include <iostream>
using namespace std; 

int table[11][11];
int R; 
int C;
int K;
int ID[11];
int F[11];
int V[11];
void count()
{
	int i;
	for(i=0;i<R;i++)
	{
	 	if(!V[i]){
		 ID[i]++;
		 int k;
		 for(k=0;k<C;k++)
			if(!table[i][k])
				F[i]++;
		int j;
		for(j=i+1;j<R;j++)
		{
			int k; bool flag=false;
			for(k=0;k<C;k++)
			{
				if(table[i][k]!=table[j][k])
				 break;
			}
			if(k==C){
				ID[i]++;
				V[j]=true;
				}
			}
		}
	}

	int max=-1;
	for(i=0;i<R;i++)
	{
		cout<<i<<" "<<ID[i]<<" "<<F[i]<<endl;
		if(ID[i] && !V[i]){
			int q=K-F[i];
			if(q%2==0){
				if(max<q)
					max=ID[i];

			}
		}

	}

	cout<<max<<endl;
}

int main(){
	freopen("15.txt","r",stdin);
	cin>>R>>C>>K;

	int i, j;
	for(i=0;i<R;i++)
		for(j=0;j<C;j++){
			char c;
			cin>>c;
			table[i][j]=c-'0';
	}
	count();

		
}
