#include<stdio.h>
#include<stdlib.h>
int find_element(int a[], int start, int end, int element){
    int mid = start +(end-start)/2;
    if(a[mid] == element)
        return mid;
    if(a[mid] < a[end]){ // Case 3
        /* If key is greater than mid but less than end
           look in right part*/
        if(element > a[mid] && element <= a[end]){
            return find_element(a,mid+1,end, element);
        }
        /* If element is greater than end, we need to look
           in left part */
        else if (element > a[end]){
            return find_element(a, start, mid-1,element);
        }
    }
    /*Case where we are in left part of the rotation */
    else if(a[mid] > a[start]){ // Case 2
        /* If key is less than mid and greater than start
           look in left part*/
        if(element < a[mid] && element >= a[start] ){
            return find_element(a,start,mid-1, element);
        }
        else
            return find_element(a,mid+1,end, element);
    }
}
int main(){
    int a[] = {11,12,14,2,3,4,5,6,7,8,9};
    int n = sizeof(a)/sizeof(a[0]);
    printf("%d\n", find_element(a,0,n,9));
    return 0;
}
