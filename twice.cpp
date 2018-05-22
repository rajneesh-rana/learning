    #include <bits/stdc++.h>
    using namespace std;
    deque<int> mn;
    deque<int> mx;
    deque<int> q;
    void push(int x)
    {
        while(!mn.empty() && mn.back() > x) {
            mn.pop_back();
        }
        mn.push_back(x);
     
        while(!mx.empty() && mx.back() < x) {
            mx.pop_back();
        }
        mx.push_back(x);
        q.push_back(x);
       }
    void pop()
    { 
        for(auto a: mn)
            cout<<a<<" ";
        cout<<endl; 
        for(auto a: mx)
            cout<<a<<" ";
        cout<<endl; 
        for(auto a: q)
            cout<<a<<" ";
        cout<<endl; 

        if(q.front() == mn.front()) {
            mn.pop_front();
        }
        if(q.front() == mx.front()) {
            mx.pop_front();
        }
        q.pop_front();
    }
    int main()
    {
        int a[]={4, 5, 100, 9, 10, 11, 12, 15, 200};
        int n=sizeof(a)/sizeof(int);
        int i;
        int j;
        int cmx;
        int cmn;
        int l;
        int r;
        int ans = 0;
     
        j = 0;
        
        for(i = 0; i < n; i++) {
            push(a[i]);
            cmx = mx.front();
            cmn = mn.front();
            while(2*cmn <= cmx) {
                pop();
                cmx = mx.front();
                cmn = mn.front();
                j++;
            }
            if((i-j+1) > ans) {
                ans = i-j+1;
                l = j;
                r = i;
            }
        }
        cout<<n-ans<<endl;
     
    }
     
