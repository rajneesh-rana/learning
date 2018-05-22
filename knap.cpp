/* A Naive recursive implementation of 0-1 Knapsack problem */
#include<stdio.h>
 
// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b)? a : b; }
 
// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
   // Base Case
   if (n == 0 || W == 0)
       return 0;
 
   // If weight of the nth item is more than Knapsack capacity W, then
   // this item cannot be included in the optimal solution
   if (wt[n-1] > W)
       return knapSack(W, wt, val, n-1);
 
   // Return the maximum of two cases: (1) nth item included (2) not included
   else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),
                    knapSack(W, wt, val, n-1)
                  );
}
int w[100]={0,};


int knap1(int W, int wt[], int val[], int n)
{
	int i=0,j=0;
	int w[100]={0};
#define INF 99999
	w[0]=0;
	for(i=1;i<=W;i++)
		w[i]=INF;
	
	for(i=0;i<n;i++)
	{
	
	for(j=wt[i];j<=W;j++)
	{
		if(w[j]>w[j-wt[i]]+val[i])
			w[j]=w[j-wt[i]]+val[i];
	}
	}
	return w[W];
}


int knap(int W, int wt[], int val[], int n)
{
	int i=0,j=0;
	for(i=0;i<n;i++)
	{
	
	for(j=wt[i];j<=W;j++)
	{
		if(j%wt[i]==0)
		{
			
			if(w[j]==0 || w[j]>  (j/wt[i])*val[i])
				 w[j]= (j/wt[i])*val[i];
//			printf(" %d %d %d %d \n", j , wt[i], w[j], (j/wt[i])*val[i]);
		}
		else if (w[j]!=0)
		{
			if(w[j] > w[j-wt[i]] + val[i])// w[j-wt[i]]+val[i])
			w[j]=w[j-wt[i]] + val[i];
		}

	}

	}
		
	for(j=1;j<=W;j++)	{
	 	printf(" %d ",w[j]);

	}
	return w[W];
} 
// Driver program to test above function
int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W ;
	scanf("%d",&W);
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d", knapSack(W, wt, val, n));
    printf("%d", knap1(W, wt, val, n));
	
	printf(" \n\n\n");
    printf("%d", knap(W, wt, val, n));
    return 0;
}
