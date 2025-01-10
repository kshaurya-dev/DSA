/*Move all zeroes in an array to the right , maintaining the overall
order of non-zero elements in the aaray
--------TWO POINTERS APPROACH-----------*/
#include<bits/stdc++.h>
int main(){
    std::vector<int>nums={1,0,0,2,3,4,0,0,5,0,0,6};
    int left=0;
    for(int i =0 ; i<nums.size() ; ++i){
        if(nums[i]!=0) std::swap(nums[left++],nums[i]);
    }
    for(auto& el:nums) std::cout<<el<<' ';
    return 0;
    /*We take a pointer place it to the right* , iterate through nums
    , found a non zero ? swap it at left , increment left*/
}