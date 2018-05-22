#include<bits/stdc++.h>
using namespace std;
 
float median(int [], int); /* to get median of a sorted array */
float  getMedian(int ar1[], int ar2[], int n)
{
    /* return -1  for invalid input */
    if (n <= 0)
        return -1;
    if (n == 1)
    {
        cout<<"n1 1 "<<ar1[0]<<" "<<ar2[0]<<endl;
        return ((float)ar1[0] + ar2[0])/2;
    }
    if (n == 2){
        cout<<"n2 2 "<<ar1[0]<<" "<<ar1[1]<<" "<<ar2[0]<<" "<<ar2[1]<<endl;
        return ((float) ((float)(max(ar1[0], ar2[0])) + min(ar1[1], ar2[1]))) / 2;
    }
    float m1 = median(ar1, n); /* get the median of the first array */
    float m2 = median(ar2, n); /* get the median of the second array */
    cout<<"M "<<m1<<" "<<m2<<" "<<n<<endl; 
    /* If medians are equal then return either m1 or m2 */
    if (m1 == m2)
        return m1;
 
    /* if m1 < m2 then median must exist in ar1[m1....] and
        ar2[....m2] */
    if (m1 < m2)
    {
        if (n % 2 == 0)
            return getMedian(ar1 + n/2, ar2, n - n/2);
        return getMedian(ar1 + n/2, ar2, n - n/2);
    }
 
    /* if m1 > m2 then median must exist in ar1[....m1] and
        ar2[m2...] */
    if (n % 2 == 0)
        return getMedian(ar2 + n/2, ar1, n - n/2);
    return getMedian(ar2 + n/2, ar1, n - n/2);
}
 
/* Function to get median of a sorted array */
float median(int arr[], int n)
{
    if (n%2 == 0)
        return ((float)arr[n/2] + arr[n/2-1])/2;
    else
        return arr[n/2];
}
 
/* Driver program to test above function */
int main()
{
    int ar1[] = {1, 2,3,4,5};
    int ar2[] = {6,7,8,9,10};
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    if (n1 == n2)
        printf("Median is %.2lf\n", getMedian(ar1, ar2, n1));
    else
        printf("Doesn't work for arrays of unequal size\n");
    return 0;
}


