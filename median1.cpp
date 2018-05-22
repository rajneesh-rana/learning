#include<stdlib.h>
#include<stdio.h>

#define MIN(a, b) a < b ? a : b

int findKthElement(int a[], int b[], int sizeA, int sizeB, int k){
    /* to maintain uniformaty, we will assume that size_a is smaller than size_b
    else we will swap array in call :) */
    if(sizeA > sizeB)
        return findKthElement(b, a, sizeB, sizeA, k);
        /* Now case when size of smaller array is 0 i.e there is no elemt in one array*/
        if(sizeA == 0)
           return b[k-1]; // due to zero based index
        
        /* case where K == 1 that means we have hit limit */
        if(k == 1)
            return MIN(a[0], b[0]);

        /* Now the divide and conquer part */

        int i =  MIN(sizeA, k/2) ; // K should be less than the size of array  
        int j =  MIN(sizeB, k/2) ; // K should be less than the size of array  

        if(a[i-1] > b[j-1])
            // Now we need to find only K-j th element
            return findKthElement(a, b+j, i, sizeB-j, k-j);
        else
            return findKthElement(a+i, b, sizeA-i, j,  k-i);

        return -1;
}

float  findMedian(int a[], int b[], int sizeA, int sizeB){
    int left  =  (sizeA + sizeB + 1) >>1;
    int right =  (sizeA + sizeB + 2) >>1;

    //if sum of two sizes is odd, return the middle element
    if((sizeA + sizeB) & 0x01){
        return findKthElement(a,b, sizeA, sizeB, left);
    }
    else{
        return (float) ((findKthElement(a,b, sizeA, sizeB, left) +
                      findKthElement(a,b, sizeA, sizeB, right))/2.0);
    }
}
int main(){

    int a[] = {10,30,40,50,60,70};
    int b[] = {30,55,100,110,115,135};

    //  int c [] = {10,30,30,40,50,55,60,100,110,115,135}
    
    int size_a  = sizeof(a)/sizeof(a[0]);
    int size_b  = sizeof(b)/sizeof(b[0]);

    printf("\nMedian is : %f", findMedian(a,b,size_a, size_b));
    return 0;
}

