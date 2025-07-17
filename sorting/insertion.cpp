#include<bits/stdc++.h>
using namespace std;
void insertion_sort(vector<int>&nums){
    for(int i =1 ; i<nums.size() ; ++i){
        int key=nums[i];
        int j = i-1;
        while(j>=0 && nums[j]>key){
            nums[j+1]=nums[j];
            j--;
        }
        nums[j+1]=key;
    }
}
int main(){
    vector<int>nums={9,8,7,65,4,3,2};
    insertion_sort(nums);
    for(auto& num:nums)cout<<num<<" ";
    return 0;
}