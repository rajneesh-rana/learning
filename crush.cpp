#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
static ll arr[10000002];
int main() {
	freopen("test.txt","r",stdin);
    int  num, cases;
    cin>>num>>cases;
    int tmp=0;
    ll a,b, k;
    while(tmp<cases){
        cin>>a>>b>>k;
        arr[a]+=k;
        arr[b]+=k;            
        tmp++;
    }
    
    tmp=0;
    k=-111111;
    while(tmp<num){
        if(arr[tmp]>k)
            k=arr[tmp];
        tmp++;
        
    }
        
    cout<<k;
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

