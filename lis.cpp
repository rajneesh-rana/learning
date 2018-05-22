// A recursive solution for subset sum problem
#include <stdio.h>
 
int S[100][100];

#if 1
// Returns true if there is a subset of set[] with sun equal to given sum
int  isSubsetSum(int set[], int n, int sum)
{
	
	int i,j;

	for(i=0;i<=n;i++)
			S[i][0]=1;

	for(i=1;i<=sum;i++)
			S[0][i]=0;
	for(i=1;i<=n;i++)
  {
		for(j=1;j<=sum;j++)
		{
					if(j-set[i-1]>=0)
				S[i][j]=S[i-1][j]+S[i-1][j-set[i-1]];
					else
				S[i][j]=S[i-1][j];
		}
	}

	for(i=0;i<=n;i++)
  {
		for(j=0;j<=sum;j++){
			printf(" %d",S[i][j]);
		}
		printf("\n");
	}

  return S[n][sum];
}
#endif
#if 0
int isSubsetSum(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if there is a subset of set[0..j-1]
    //  with sum equal to i
    int  subset[sum+1][n+1];
 
    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
      subset[0][i] = 1;
 
    // If sum is not 0 and set is empty, then answer is false
    for (int i = 1; i <= sum; i++)
      subset[i][0] = 0;
 
     // Fill the subset table in botton up manner
     for (int i = 1; i <= sum; i++)
     {
       for (int j = 1; j <= n; j++)
       {
         subset[i][j] = subset[i][j-1];
         if (i >= set[j-1])
           subset[i][j] = subset[i][j] + subset[i - set[j-1]][j-1];
       }
     }
 
    /* // uncomment this code to print table
     for (int i = 0; i <= sum; i++)
     {
       for (int j = 0; j <= n; j++)
          printf ("%4d", subset[i][j]);
       printf("\n");
     } */
 
     return subset[sum][n];
} 
#endif 
// Driver program to test above function
int main()
{
  int set[] = {3, 34, 4, 12, 5, 2};
	//int set[] = {2,3,4,5,12,34};
  int sum = 9;
  int n = sizeof(set)/sizeof(set[0]);
  printf(" %d ",isSubsetSum(set, n, sum));
  return 0;
}
