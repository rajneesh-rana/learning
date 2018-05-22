#include <iostream>
#include <vector>
using namespace std;

#define MAX 10
vector<int> A;
int partitions(int low,int high)
{
    int p=low,r=high,x=A[r],i=p-1;
    for(int j=p;j<=r-1;j++)
    {
        if (A[j]<=x)
        {

            i=i+1;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}
int selection_algorithm(int left,int right,int kth)
{
    for(;;)
    {
        int pivotIndex=partitions(left,right);          //Select the Pivot Between Left and Right
        cout<<pivotIndex<<" "<<kth<<endl;
        int len=pivotIndex-left+1;

        if(kth==len-1)
            return A[pivotIndex];

        else if(kth<len)
            right=pivotIndex-1;

        else
        {
            kth=kth-len;
            left=pivotIndex+1;
        }
    }
}


int main()
{
   vector<int> B= {1,3,41,22,11,12,13};
   A=B;
   cout<<selection_algorithm(0,B.size()-1,B.size()/2)<<endl;
    return 0; 

}
