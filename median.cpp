#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> A={1,2,3,4};
    vector<int> B={5,6,7,8,9};
    int m = A.size(), n = B.size();
  //      if (m > n) return findMedianSortedArrays(B, A);
        int imin, imax, i, j; 
        imin = 0;
        imax = m;
        int ans=1.0;
        while (imin <= imax) {
            i = (imin + imax)/2;
            j = (m+n+1)/2 - i;
            if (j > 0 && i < m && B[j - 1] > A[i]) {
                imin = i + 1;
            } else if (i > 0 && j < n && A[i - 1] > B[j]) {
                imax = i - 1;
            } else {
                // Figure out median now. 
                int median1 = 0, median2 = 0;
                if (i == 0) {
                    median1 = B[j - 1];
                } else if (j == 0) {
                    median1 = A[i - 1];
                } else {
                    median1 = max(A[i - 1], B[j - 1]);
                }
                if ((m+n) % 2 == 1) {
                    ans=1.0 * median1;
                    break;
                }
                if (i == m) {
                    median2 = B[j];
                } else if (j == n) {
                    median2 = A[i];
                } else {
                    median2 = min(A[i], B[j]);
                }
                    ans=1.0 * (median1 + median2) / 2.0;
                break;
            }
      }
      cout<<ans<<endl;
}

