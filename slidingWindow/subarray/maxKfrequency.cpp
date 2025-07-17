/*LEETCODE 2958 - find number and longest subarray in which all elements have a frequency of k at most*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    std::vector<int>nums={1,2,3,1,2,3,1,2};
    int k=2;
    unordered_map<int,int>hash;
    int left=0;
    int res=0;
    int count=0;
    for(int right =0 ; right < nums.size() ; right++){
        hash[nums[right]]++;
        while(hash[nums[right]]>k){
            if(--hash[nums[left++]]==0)hash.erase(nums[left]);
        count+=nums.size()-right;
        res=std::max(res , right - left+1);
    }
    cout<<"max subarray size = "<<res;
    cout<<"\n number of subarrays = "<<count;
    return 0;
}