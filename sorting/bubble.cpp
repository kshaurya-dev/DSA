#include<bits/stdc++.h>
using namespace std;
void bubble_sort(vector<int>&nums){
    for(int i =0 ; i<nums.size() ; ++i){
        for(int j =0 ; j<nums.size()-i-1 ; j++){
            if(nums[j]>nums[j+1])swap(nums[j] ,nums[j+1]);
        }
    }
}
int main(){
    vector<int>nums={9,8,7,65,4,3,2};
   bubble_sort(nums);
    for(auto& num:nums)cout<<num<<" ";
    return 0;
}