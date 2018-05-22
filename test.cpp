#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int NMAX = 100010;

int N, M, X, Y, K, MaxDown[NMAX], MaxUp[NMAX], Diam;
vector<int> G[NMAX];
bool UsedUp[NMAX], UsedDown[NMAX];

void DFSDown(int Node)
{
    UsedDown[Node] = 1;
    for(int i = 0; i < G[Node].size(); ++ i)
    {
        int Vec = G[Node][i];
        if(!UsedDown[Vec])
        {
            DFSDown(Vec);
            MaxDown[Node] = max(MaxDown[Node], MaxDown[Vec] + 1);
        }
    }
}

void DFSUp(int Node)
{
    UsedUp[Node] = 1;
    int Max = 0;

    for(int i = 0; i < G[Node].size(); ++ i)
    {
        int Vec = G[Node][i];
        if(UsedUp[Vec]) continue;
        MaxUp[Vec] = Max + 1;
        Max = max(Max, MaxDown[Vec] + 1);
    }

    Max = 0;

    for(int i = int(G[Node].size()) - 1; i >= 0; -- i)
    {
        int Vec = G[Node][i];
        if(UsedUp[Vec]) continue;
        MaxUp[Vec] = max(MaxUp[Vec], Max + 1);
        MaxUp[Vec] = max(MaxUp[Vec], MaxUp[Node] + 1);

        Max = max(Max, MaxDown[Vec] + 1);
        DFSUp(Vec);
    }
}

int main()
{
    freopen("dummy.txt", "r", stdin);
   // freopen("test.out", "w", stdout);

    scanf("%i %i", &N, &M);
    for(int i = 1; i < N; ++ i)
    {
        scanf("%i %i", &X, &Y);
        G[X].push_back(Y);
        G[Y].push_back(X);
    }

 
    DFSDown(1);
    DFSUp(1);

    for(int i = 1; i <= N; ++ i){
        cout<<MaxDown[i]<<" "<<MaxUp[i]<<endl;
         Diam = max(Diam, max(MaxDown[i], MaxUp[i]));
    }
    cout<<endl;
    for(; M; M --)
    {
        scanf("%i %i", &X, &K);
        printf("%lld\n", max(MaxUp[X], MaxDown[X]) + 1LL * (K - 1) * Diam);
    }

}

