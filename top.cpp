#include<iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <stack>
#define NIL -1
#include <stdio.h>
using namespace std;

stack<int> Q;

int N, K;
vector<int> L[10001];

struct node {
	int i;
	int d;
} NODES [10001];

int V[10001];
int R[10001];

bool comp(const  node &a, const node &b){
	return (a.d<b.d || (a.d==b.d  && a.i>b.i));
}

bool trav(int s, int re[]){

	int i, j;
	V[s] = true;
	R[s] = true;
	int flag = true;
	for (i = 0; i < L[s].size(); i++){
		if (!V[L[s][i]]){
			flag=trav(L[s][i], re);
		}
		else if (R[L[s][i]]){
			return false;
		}
	}
	R[s] = false;
	Q.push(s);
	return flag;
}

void dfs(){
	
	int i, j;
	int flag = true;
//	for (i = 1; i <= N; i++)
//		cout<<NODES[i].i<<" "<<NODES[i].d<<endl;
	
	for (i = 1; i <= N; i++){
		if (!V[NODES[i].i]){
			if (!trav(NODES[i].i, R))
				flag = false;
		}
	}

	if (!flag)
		cout << "Sandro fails.\n";
	else{
		while (!Q.empty()){
			cout << Q.top() << " ";
		Q.pop();
		}
		cout << endl;
	}

}
int main()
{
	freopen("top.txt", "r", stdin);
		scanf("%d %d",&N,&K);
	int i, j;
	
	
	for (i = 1; i <= N; i++)
		NODES[i].i=i;
	int e1, e2;
	for (i = 1; i <= K; i++){
		scanf("%d %d",&e1,&e2);
		NODES[e2].i=e2;
		NODES[e2].d++;
		L[e1].push_back(e2);
	}
	
	sort(NODES+1, NODES+N+1, comp);

	dfs();
	return 0;
}
