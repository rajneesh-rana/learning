#include<iostream>
#include<vector>
using namespace std;

int check(vector<int> &nums,int target)
{
int first=0, last=nums.size(), mid;
        while (first<last) {
            mid=first+((last-first)>>1); // first<=mid, mid<last
            /// if comp(item,target)==false, advance first
            // if(nums[mid]<=target) // for upper_bound
            if (nums[mid]<target) // for lower_bound
                first=mid+1; // first always increases
            else /// else recede last
                last=mid; // last always decreases (even last-first==1)
        }
        return first;
}

int main()

{
    int a;
    cin>>a;
    vector<int> A={1,23,44,55,69,78,101,112};
    cout<<A[check(A,a)]<<endl;

}
