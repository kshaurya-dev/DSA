/*LEETCODE 1658 - reduce a number to zero by choosing either left or right of 
array , choosing so changes the array forever , return the minimum operations
to do so*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    std::vector<int>nums={1,1,4,2,3};
    int x=5;
    /*so this quuestion blew my blew my fucking mind when i first saw it , for the first glance it is too
    comprehend that this is a sliding window problem !
    basically i have to find y in the array such that x-y=0 , or y=x , and its clear that y is part of 
    nums , so after choosing the right y , it leaves behind sum(nums)-y , now the sequence which sums to y
    will not always be a subrray , right ? but sum(nums)-x would be !!! 
    so just search to the maximum size window with sum = sum(nums)-x , that's it !*/
    int sum=0;
    for(auto& num : nums)sum+=num;
    int k = sum - x;//search for max subraray with sum=k , as 'x' sum subarray has to be minimum
    int left=0;
    int  sub_sum=0;
    int res=INT_MAX;
    int n = nums.size();
    for(int right=0 ; right<nums.size() ; right++){
        sub_sum+=nums[right];
        while(sub_sum>k && left<=right)sub_sum-=nums[left++];
        if(sub_sum==k)res=min(res, n-right+left-1);
    }
    if(res==INT_MAX)cout<<"-1";
    cout<<res;
    return 0;
}
