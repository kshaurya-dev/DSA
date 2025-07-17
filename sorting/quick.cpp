#include<bits/stdc++.h>
using namespace std;
int partition(int l , int h,vector<int>&nums){

    int pivot=nums[l];
    int i=l;
    int j = h;
    while(i<j){
        while(nums[i]<=pivot)i++;
        while(nums[j]>pivot)j--;
        if(i<j) std::swap(nums[i] , nums[j]); 
    }
    std::swap(nums[l],nums[j]);
    return j;
}
void quick_sort(int l , int h , vector<int>&nums){
    if(l<h){
        int j=partition(l,h,nums);
        quick_sort(l,j,nums);
        quick_sort(j+1,h,nums);
    }
}
int main(){
    vector<int>nums={9,8,76,5,4,3,2,1};
    quick_sort(0,nums.size()-1,nums);
    for(auto& el : nums)cout<<el<<" ";
    return 0;
}