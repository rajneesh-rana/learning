#include<bits/stdc++.h>

using namespace std;
static int M[10001][10001];
static int D[10001];

int main() {
    freopen("bfs.txt","r",stdin);
    int tc;
    cin>>tc;
    while(tc--){
        int N, K;
        cin>>N>>K;
        int i,j,k;
        
        for(i=1;i<=N;i++)
            for(j=1;j<=N;j++){
            M[i][j]=0;
            M[j][i]=0;
        }
        
        for(i=1;i<=K;i++){
            cin>>j>>k;
            M[j][k]=1;
            M[k][j]=1;
        }
        
        int S;
        cin>>S;
         for(i=1;i<=N;i++){
             D[i]=-1;
          }
        
        queue<int> Q;
        bool V[N];
         memset(V, false, sizeof(V));
        
        D[S]=0;
        V[S]=1;
        Q.push(S);
        
        while(!Q.empty()){
            int n=Q.front();
            Q.pop();
            for(i=1;i<=N;i++){
                if(M[n][i] && !V[i]){
                    D[i]=D[n]+1;
                    V[i]=1;
                    Q.push(i);                                  
                }
            }          
        }
        
       for(i=1;i<=N;i++){               
               if(D[i]==-1)
                    cout<<"-1"<<" ";
               else if(D[i]==0)
                   {}
               else
                   cout<<D[i]*6<<" ";
             
        }
        cout<<endl;
                
    }    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
