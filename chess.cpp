

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
//#include <queue>
using namespace std;

struct Node{
    int n;
    int count;
    unsigned char steps[200];
    int top;
};
#if 1

struct queue{
    Node node[201];
    int top;
    int bottom;
    void push(Node N){
        node[top]=N;
        top++;
    }
    Node front(){
        return node[bottom];
    }
    void pop(){
     bottom++;        
    }
    bool empty(){
        if(top==bottom) 
            return true;
        else
            return false;       
    }    
    void clear(){
        top=bottom=0;       
    }
};
#endif 


int main() {
    int tc;
    freopen("chess.txt","r",stdin);
    cin>>tc;
    while(tc--){
        int move[101]={0,};
	bool V[101]={0,};
        int L, S;

        cin>>L;
        int i,j;
        for(i=1;i<=L;i++){
           int e1, e2;
           cin>>e1>>e2;
            move[e1]=e2;        
        }
        cin >>S;
        for(i=1;i<=S;i++){
           int e1, e2;
           cin>>e1>>e2;
            move[e1]=e2;        
        }
//cout<<L<<" "<<S<<endl;        
        Node r={1,0};
	r.top=0;
        queue Q;
        Q.clear();
        Q.push(r);
	V[1]=true;
        while(!Q.empty()){
            Node u=Q.front();
	    if(u.n==100){
                break;
            }
            Q.pop();
		cout<<u.n<<" "<<u.count<<endl;	
            for(i=u.n+1;i<=u.n+6 && i<=100 ;i++){
		if(!V[i]){
                Node tmp;
		tmp.steps[tmp.top]=i;             
            	tmp.top=u.top+1;
                if(move[i]){
                    tmp.n=move[i];
                }
                else
                    tmp.n=i;
                tmp.count=u.count+1;
                Q.push(tmp);
		V[i]=true;
            }
	   }	            
        }
	Node x=Q.front();
        cout<<x.count<<endl;
	for(int i=0;i<x.top;i++)
	  cout<<x.steps[i]<<endl;
        
    }

}



