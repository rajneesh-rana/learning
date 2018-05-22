#include<stdio.h>
#include<limits.h>
#include <iostream>
using namespace std; 
// A Dynamic Programming solution for subset sum problem
#include <stdio.h>
 
// Returns true if there is a subset of set[] with sun equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if there is a subset of set[0..j-1]
    //  with sum equal to i
    int subset[sum+1][n+1];
	
	for(int i=0;i<=n;i++)
		subset[0][i]=1;

	for(int i=1;i<=sum;i++)
		subset[i][0]=false;
		
	for(int i=1;i<=sum;i++)
	{
		for(int j=1;j<=n;j++){
			int x=0,y=0;
			if(j-1>=0)
				x=subset[i][j-1];
			if(i-set[j]>=0)
				y=subset[i-set[j]][j-1];
			subset[i][j]=x+y;
		}
	}

 
    // uncomment this code to print subset
     for (int i = 0; i <= sum; i++)
     {
       for (int j = 0; j <= n; j++)
          printf ("%4d", subset[i][j]);
       printf("\n");
     } 
 
     return subset[sum][n];
}
 
// Driver program to test above function
int main()
{
  int set[] = {3, 34, 4, 12, 5, 2};
  int sum = 9;
  int n = sizeof(set)/sizeof(set[0]);
  if (isSubsetSum(set, n, sum) == true)
     printf("Found a subset with given sum");
  else
     printf("No subset with given sum");
  return 0;
}
