// Author Amit Pandey
#include<bits/stdc++.h>

using namespace std;

bool check(long long int p, long long int n)
{
    long long int temp = p , outp =0, five = 5;
    while(five < temp)
    {
      cout<<temp<<" "<<five<<endl;
        outp += temp/five;
        five = five*5;
    }
    if(outp>= n)
            return true;
    else
            return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        if(n==1)
        {
            cout<<"5"<<endl;
            continue;
        }
        long long int low =2;
        long long int high = 100*n;
        while(low <high)
        {
            long long int mid = (low+high)/2;
            if(check(mid,n) == true)
                    high = mid;
            else
                    low = mid+1;
        }
        cout<<low<<endl;
    }
    return 0;
}
