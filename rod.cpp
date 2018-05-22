#include<stdio.h>
#include<limits.h>
 
// A utility function to get the maximum of two integers
int max(int a, int b) { return (a > b)? a : b;}
 
/* Returns the best obtainable price for a rod of length n and
   price[] as prices of different pieces */
int cutRod(int price[], int n)
{
   if (n <= 0)
     return 0;
   int max_val = INT_MIN;
 
   // Recursively cut the rod in different pieces and compare different 
   // configurations
   for (int i = 0; i<n; i++)
         max_val = max(max_val, price[i] + cutRod(price, n-i-1));
 
   return max_val;
}
int knap1(int W, int wt[], int val[], int n)
{
        int i=0,j=0;
        int w[100]={0};
#define INF -99999
        w[0]=0;
        for(i=1;i<=W;i++)
                w[i]=INF;

        for(i=0;i<n;i++)
        {

        for(j=wt[i];j<=W;j++)
        {
                if(w[j]<w[j-wt[i]]+val[i])
                        w[j]=w[j-wt[i]]+val[i];
        }
        }
        return w[W];
}

 
/* Driver program to test above functions */
int main()
{
	int arr[] = {2, 5, 8, 3, 10, 1, 1, 20};
	int s[]={1,2,3,4,5,6,7,8};


    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Obtainable Value is %d\n", knap1(size,s,arr,size));
    printf("Maximum Obtainable Value is %d\n", cutRod(arr, size));
    getchar();
    return 0;
}
