#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int G[501][501];
int R, C;

int per()
{
    int r1=1, r2=R, c1=1, c2=C;
    bool R1, R2,C1,C2;
    R1=R2=C1=C2=0;
    int i;
   
    int flag=true;
    while(flag){
        bool check=true;
        for(i=c1;i<=c2 && !R1 ;i++)
        {
           // area++;
            if(G[r1][i]==120){
                cout<<"======"<<endl;
                check=false;
                r1++;
                break;
            }           
        }
        if(!check)
            continue;
        else
            R1=1;
        
        for(i=r1;i<=r2 && !C1;i++)
        {
           if(G[i][c1]==120){
                check=false;
                c1++;
                break;
            }           
        }
        if(!check)
            continue;
        else
            C1=1;
        
        for(i=c1;i<=c2 && !R2 ;i++)
        {
            //area++;
            if(G[r2][i]==120){
                check=false;
                r2--;
                break;
            }           
        }
        if(!check)
            continue;
        else
            R2=1;
        
        for(i=r1;i<=r2 && !C2;i++)
        {
            //area++;
            if(G[i][c2]==120){
                check=false;
                c2--;
                break;
            }           
        }
        if(!check)
            continue;
        else
            C2=1;
        
        if(R1 && R2 && C1 && C2 )
           flag=false;
    }
    cout<<r2<<" "<<r1<<" "<<c1<<" "<<c2<<endl;
    
    return 1;
    
}
int main() {
	freopen("per.txt","r",stdin);
    cin>>R>>C;
    string s;
    int i=1, j;
 
    while(i<=R){
        cin>>s;        
        for(j=1;j<=C;j++){
            G[i][j]=s[j-1];            
        }  
        i++;
    }

    for(i=1;i<=R;i++){
      for(j=1;j<=C;j++)
          cout<<(char)G[i][j];
        cout<<endl;
    }
     
    cout<<per()<<endl;
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
