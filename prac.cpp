#include<stdio.h>
#include<iostream>
#include <stdlib.h>
   using namespace std; 
// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{

    int tem=arr[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++)
    {
        if(arr[j]<=tem)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    cout<<"partition "<<low<<" "<<high<<" "<<i+1<<endl;    
    return (i+1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if(low<high)
    {
        int p=partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
 
}
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int A[100];
int t;
int main()
{
    cin>>t;

    for(int i=0;i<t;i++)
       A[i]=rand()/10000;

    for(int i=0;i<t;i++)
        cout<<A[i]<<" ";
    cout<<endl<<endl;
   quickSort(A,0,t-1);
 //     quickSort(A,0,t-1);

    for(int i=0;i<t;i++)
        cout<<A[i]<<" ";

    cout<<endl;
}
 
