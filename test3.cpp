// A space efficient C program to rearrange contents of
//  arr[] such that arr[j] becomes j if arr[i] is j
#include<stdio.h>
 
// A utility function to rearrange elements in the cycle
// starting at arr[i]. This function assumes values in
// arr[] be from 1 to n.  It changes arr[j-1] to i+1
// if arr[i-1] is j+1
void rearrangeUtil(int arr[], int n, int i)
{
    // 'val' is the value to be stored at 'arr[i]'
    int val = -(i+1);  // The next value is determined
                       // using current index
    i = arr[i] - 1;  // The next index is determined
                     // using current value
 
    // While all elements in cycle are not processed
    while (arr[i] > 0)
    {
        // Store value at index as it is going to be
        // used as next index
        int new_i = arr[i] - 1;
 
        // Update arr[]
        arr[i] = val;
 
        // Update value and index for next iteration
        val = -(i + 1);
        i = new_i;
    }
}
 
// A space efficient method to rearrange 'arr[0..n-1]'
// so that 'arr[j]' becomes 'i' if 'arr[i]' is 'j'
void rearrange(int arr[], int n)
{
    // Increment all values by 1, so that all elements
    // can be made negative to mark them as visited
    int i;
    for (i=0; i<n; i++)
        arr[i]++;
 
    // Process all cycles
    for (i=0; i<n; i++)
    {
       // Process cycle starting at arr[i] if this cycle is
       // not already processed
       if (arr[i] > 0)
          rearrangeUtil(arr, n, i);
    }
 
    // Change sign and values of arr[] to get the original
    //  values back, i.e., values in range from 0 to n-1
    for (i=0; i<n; i++)
          arr[i] = (-arr[i]) - 1;
}
 
// A utility function to print contents of arr[0..n-1]
void printArray(int arr[], int n)
{
    int i;
    for (i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Drive program
int main()
{
    int arr[] =  {2, 0, 1, 4, 5, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, n);
 
    rearrange(arr,  n);
 
    printf("Modified array is \n");
    printArray(arr, n);
    return 0;
}
