// A C++ program to print topological sorting of a DAG
#include<iostream>
#include <list>
#include <stack>
#include <vector>
#include <stdio.h>
using namespace std;

vector<int> V[10001];
vector<int> order;
int in[10001];
int cnt;
int  heap[100001];
int heapsize;
void init(){
    heapsize=0; 
}
void insert(int  n){
    heapsize++;
    heap[heapsize]=n;
    int now=heapsize;
    
    while(heap[now/2]>n){
        heap[now]=heap[now/2];
        now=now/2;
    }
    heap[now]=n;    
}

int  del()
{
    int now, child, min, last;
    min=heap[1];
    last=heap[heapsize--];
    for(now=1;now*2<=heapsize;now=child){
        child=now*2;
        if(child!=heapsize && heap[child+1]<heap[child])
            child++;
        if(last>heap[child])
            heap[now]=heap[child];
        else
            break;            
    }
    heap[now]=last;
    return min;    
}    
bool empty(){
    if(heapsize>0)
        return false;
    else
        return true;   
}
	
void topology(){
	while(!empty()){
		int n=del();
		cnt++;
		order.push_back(n);
		for(int i=0;i<V[n].size();i++){
			int j=V[n][i];
			in[j]--;
			if(!in[j])
				insert(j);
		}
	}	
}

int main(){
	freopen("top.txt","r",stdin);
	int N, K;
	cin>>N>>K;
	int tmp=K;
	while(tmp){
		int e1, e2;
		cin>>e1>>e2;
		V[e1].push_back(e2);
		in[e2]++;
		tmp--;
	}
	cnt=0;
	tmp=1;
	init();
	while(tmp<=N){
		if(!in[tmp])
			insert(tmp);
		tmp++;
	}
	topology();
	if(cnt==N){
		for(int i=0;i<order.size();i++)
			cout<<order[i]<<" ";
		cout<<endl;
	}
	else
		cout<<"Sandro fails\n";
		
	return 0;
}
