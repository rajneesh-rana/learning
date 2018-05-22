// A Naive recursive solution for Rod cutting problem
#include<stdio.h>
#include<limits.h>
#include<iostream>
using namespace std; 
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
   int cost[n+1];
   cost[0]=0;
    for (int i = 1; i<=n; i++)
        cost[i]=INT_MIN;

   for (int i = 1; i<=n; i++)
   {
        for(int j=i;j<=n;j++)
        {
            cost[j]=max(cost[j], cost[j-i]+price[i-1]);
        }
        for(int j=1;j<=n;j++)
            cout<<cost[j]<<" ";
        cout<<endl;
   }
    
    return cost[n]; 
}
 
/* Driver program to test above functions */
int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Obtainable Value is %d\n", cutRod(arr, size));
    getchar();
    return 0;
}
