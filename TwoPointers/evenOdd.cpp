/*separate even numbers to the right , odds to the left*/
#include<bits/stdc++.h>
int main(){
    std::vector<int>nums={1,2,3,4,5,6,7,8,9,10};
    int left=0;
    int right = nums.size()-1;
    while(left<right){
        if(nums[left]%2==0)++left;
        if(nums[right]%2==1)--right;
        if(nums[right]%2==0 && nums[left]%2==1){
            std::swap(nums[right],nums[left]);
            ++left;
            --right;}
    }
    /*so two pointers - left & right , if left is even ? no worries , move it.
    if right is odd? again no worries , move it. 
    so left is odd and right is even , timeto swap !*/
    for(auto& num : nums){
        std::cout<<num<<'-';
    }
    return 0;
}