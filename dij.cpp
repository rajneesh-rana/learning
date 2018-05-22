#include<bits/stdc++.h>

using namespace std;
static int M[10001][10001];
static int D[10001];
bool V[4001];
int N;
int min(){
    int min=INT_MAX;
    int index;
    for(int i=1;i<=N;i++){
        if(!V[i] && D[i]<=min){
            min=D[i];
            index=i;
        } 
    }
    return index;  
}

void DJ(int src){
    for(int i=1;i<=N;i++){
        int u=min();
        V[u]=true;
        for(int j=1;j<=N;j++){
            if(!V[j] && M[u][j] && D[u]!=INT_MAX && D[j]>D[u]+M[u][j]){
                D[j]=D[u]+M[u][j];
               }
        }
    }   
}


int main() {
	freopen("dij.txt","r",stdin);
    int tc;
    cin>>tc;
    while(tc--){
        int K;
        cin>>N>>K;
        int i,j,k,l;
        
        for(i=1;i<=N;i++)
            for(j=1;j<=N;j++){
            M[i][j]=0;
          }
        
        for(i=1;i<=K;i++){
            cin>>j>>k>>l;
           // if(!M[j][k]|| M[j][k]>l)
            {
                M[j][k]=l;
                M[k][j]=l;
            }
        }
        
      
        int S;
        cin>>S;
         for(i=1;i<=N;i++){
             D[i]=INT_MAX;           
        }
        
        D[S]=0;
        memset(V,false,sizeof(V));
        DJ(S);
     
       for(i=1;i<=N;i++){               
               if(D[i]==INT_MAX)
                    cout<<D[i]<<" ";
               else if(D[i]==0)
                   {}
               else
                   cout<<D[i]<<" ";
             
        }
        cout<<endl;


    }    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

