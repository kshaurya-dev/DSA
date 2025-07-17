#include<bits/stdc++.h>
using namespace std;
void selection_sort(vector<int>&nums){
    for(int i =0 ; i<nums.size() ; ++i){
        int min=i;
        for(int j =i ; j<nums.size(); j++){
           if(nums[j]<nums[min])min=j;
        }
        swap(nums[min], nums[i]);
    }
}
int main(){
    vector<int>nums={9,8,7,65,4,3,2};
   selection_sort(nums);
    for(auto& num:nums)cout<<num<<" ";
    return 0;
}