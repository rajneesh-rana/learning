#include <bits/stdc++.h>
using namespace std;
vector <int> c; int dp[2005]; 
int main()
{
   // int tc; cin >> tc;
    for (int g=0;g<1; g++){c.clear(); memset(dp,0,sizeof(dp)); 
    int a,b; cin >> a >> b;
	int d;
    for (int g=0;g<a; g++)
    {
    	d=g+1; c.push_back(d); 
    }sort(c.begin(), c.end());
    for (int g=1;g<=b; g++)
    {
        for (int y=0;y<c.size(); y++)
        {
            if (c[y]>g) continue;
            dp[g]=max(dp[g], c[y]+dp[g-c[y]]); 
        }
	cout<<dp[g]<<endl;
    }
    cout << dp[b] << '\n';} return 0; 
}
