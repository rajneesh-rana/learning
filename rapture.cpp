#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int D[50001];

vector<pair<int,int> > list[50001];

struct node{
    int num;
    int dist;    
};

node heap[100001];
int heapsize;
void init(){
    heapsize=0; 
}
void insert(node n){
    heapsize++;
    heap[heapsize]=n;
    int now=heapsize;
    
    while(heap[now/2].dist>n.dist){
        heap[now]=heap[now/2];
        now=now/2;
    }
    heap[now]=n;    
}

node del()
{
    int now, child;
    node min, last;
    min=heap[1];
    last=heap[heapsize--];
    for(now=1;now*2<=heapsize;now=child){
        child=now*2;
        if(child!=heapsize && heap[child+1].dist<heap[child].dist)
            child++;
        if(last.dist>heap[child].dist)
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
void DJ(int src, int N){
    
    node tmp={src,0};
    D[src]=0;
    init();
    insert(tmp);
    while(!empty()){
        node n=del();
        int u=n.num;
        if(u==N){
            return;
        }
        if(D[u]<n.dist)
            continue;
        for(int j=0;j<list[u].size();j++){
            int index=list[u][j].first;
            int w=list[u][j].second;
            int sum=D[u] + (D[u]<w?(w-D[u]):0);
            if(( D[index] > sum)){
               D[index] = sum;
               node tmp;
               tmp.num=index;
               tmp.dist=D[index];
               insert(tmp);
            }            
        }       
    }    
}

int main() {
    int N , K;
    freopen("rapture1.txt","r",stdin);
    cin>>N>>K;
  //  list=new vector<pair<int,int>>[N+1];
    
    
    int i, j,k,w;
    for(i=1;i<=N;i++){
        D[i]=INT_MAX;
    
    }
    
    for(i=1;i<=K;i++){
        cin>>j>>k>>w;
        list[j].push_back(pair<int,int>(k,w));
        list[k].push_back(pair<int,int>(j,w));     
        
    }
    
  
    
    DJ(1, N);    
  //  for(i=1;i<=N;i++)
   //     cout<<D[i]<<" ";
    if(D[N]!=INT_MAX)
        cout<<D[N]<<endl;
    else
        cout<<"NO PATH EXISTS"<<endl;
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}


