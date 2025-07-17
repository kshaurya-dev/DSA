/*LEETCODE 2962 - find number of subarrays where max element of array appears
at least k times*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    std::vector<int>nums={1,3,2,3,3};
    int k=1;
    int maxi=nums[0];
    for(auto& num : nums)if(num>maxi)maxi=num;
    int left=0;
    int count=0;
    int res=0;
    for(int right =0 ; right <nums.size() ; right++){
        if(nums[right]==maxi)count++;
        while(count>=k){
            res+=nums.size()-right;
            if(nums[left]==maxi)count--;
            left++;
        }
    }
    /* pretty straight forward , but atleast k can be consfusing , so how are we calculating subarrays?- 
    well the moment we find a subarray which is k maxis , all the subarrays that contain that particular
    subarrays will be valid as we need at lease k maxis (and this one has k maxis)
    so right = 5 => valid_subarray ++ , 
   right = 6 => valid_subarray++,
   right = 7 => valid_subarray++,
   .....................
   right=s.size()-1 => valid_subarray++,
   HENCE THE FORMULA - s.size()-right !!*/
    cout<<"no. of subarrays = "<<res;
    return 0;
}