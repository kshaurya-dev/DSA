//Find numver of subarrays with sum =k
//Sliding window Approach , works only for postive integers

#include<iostream>
#include<vector>
int main(){
    std::vector<int>nums={1,2,3};
    int k{2};
    int sum=0;
    int left=0;
    int right=0;
    int count=0;

    /*using the sliding window with two pointers - left and right.we increment sum
    with right pointer , increasing it. Now the same might become equal to or greater
    than k.if it goes beyond k , time to shrink the window and increment left forth
    as long as our sum is again lesser than or equal to k.count is incremented everytime sum is equal to k */

    while(right<nums.size()){
        sum+=nums[right];
        while(sum>k){
            sum=sum-nums[left];
            left++;
        }
        if(sum==k){
            count++;
        }
        right++;
    }
    std::cout<<count;
    return 0;
}