#include<bits/stdc++.h>

using namespace std;

long long int A[2000009];

bool compare( pair<long long int , long long int > V1 , pair<long long int , long long int > V2)
{
    if(V1.first != V2.first)
        return V1.first < V2.first;
    else
        return V1.second >V2.second;
}


int main()
{
freopen("test.txt","r",stdin);
    long long int N,M,i,k;
    cin>>N>>M;
      assert(3<=N);
    assert(N<=10000000);
   assert(1<=M);
   assert(M<=200000);
    vector < pair<long long int , long long int > > V;
    for(i=1 ; i<=M ; i++)
    {
        long long int a,b;
        cin>>a>>b>>k;
       assert(1<=a);
        assert(a<=N);
        assert(1<=b);
        assert(b<=N);
        assert(a<=b);
        assert(0 <= k);
        assert(k<= 10000000);
        V.push_back(make_pair(a,k));
        V.push_back(make_pair(b,(-1)*k));
    }
    sort(V.begin(), V.end(), compare);
    for(i=0 ; i< V.size() ; i++)
       cout<<V[i].first<<" "<<V[i].second<<endl;
	
	cout<<endl<<endl;
    for(i=0 ; i<2*M; i++){
        A[i] = V[i].second;
	cout<<A[i]<<endl;
	}
	cout<<endl<<endl;
    for(i=1 ; i<2*M ; i++){
	cout<<"::i"<<i<<" "<<A[i]<<" "<<A[i-1]<<endl;
        A[i] = A[i-1]+A[i];
	}
    sort(A,A+2*M);
    cout<<A[2*M -1]<<endl;
    return 0;
}
