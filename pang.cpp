#include<iostream>
#include<cstdio>
#include<ctime>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
#include<iterator>
using namespace std;
int a[1001], b[1003], h, k, n, nk, z,  zz, barrier;
struct pointJ {
 pointJ() {
  next =  NULL;
  prev = NULL;
 };
 
 int  count;
 int num;
 int dead;
 pointJ *next;
 pointJ *prev;
};
void flow (int pos) {
 int i, j;
 if (h >= k) {
  return;
 }
 if (b[pos] == b[pos + 1]) {
  b[pos]++;
  h++;
  for (j = pos + 1; j <= nk - h; j++) {
   b[j] = b[j + 1];
  }
  
  // check left
  for (j = pos - 1; j >= barrier; j--) {
   if (b[j] == b[j + 1]) {
    pos = j;
   } else {
    break;
   }
  }
  flow(pos);
    
 } else {
  if (pos + 1 <= n) {
   flow(pos + 1);
  }
 }
}
int main(int argc, char** argv) {
//ios_base::sync_with_stdio(0);
#if 1
 double ctime1 = (double)clock() / CLOCKS_PER_SEC, ctime2;
 freopen("pang.txt", "r", stdin);
 //freopen("../../tests/gentest1.txt", "r", stdin);
#endif
 int tests, tc;
 int i, j, max, l, u;
 cin >> tests;
 for (tc = 1; tc <= tests; tc++) {
  cin >> n >> k;
  max = 0;
  nk = n + k;
  h = 0;
  for (i = 1; i <= n + k; i++) {
   cin >> a[i];
  }
  if (n == 1) {
   cout << "Case #" << tc << endl << a[1] << endl;
   continue;
  }
  pointJ *listStart = new pointJ(), *temp, *listEnd;
  temp = listStart;
  
  a[0] = -1;
  max = a[1];
  for (u = 1; u < n - 1; u++) {
   for (i = 1; i <= n + k; i++) {
    b[i] = a[i];
   }
   h = 0;
   barrier = u;
   flow(u);   
   for (i = 1; i <= n; i++) {
    if (max < b[i]) {
     max = b[i];
    }   
   }
  }
  

  cout << "Case #" << tc << endl << max << endl;  
 } 
#if 1//__ATHOME
 ctime2 = (double)clock() / CLOCKS_PER_SEC;
 cout << ctime2 - ctime1;
#endif
return 0;
}
 
