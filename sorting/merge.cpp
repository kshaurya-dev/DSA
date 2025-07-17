#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>&nums , int l , int mid  , int h){
    vector<int>temp;
    int k=0;
    int i =l;
    int j =mid+1;
    while(i<=mid && j<=h){
        if(nums[i]<=nums[j])temp.emplace_back(nums[i++]);
        else  temp.emplace_back(nums[j++]);
    }
    while(i<=mid) temp.emplace_back(nums[i++]);
    while(j<=h)temp.emplace_back(nums[j++]);
    for(int m =0   ; m<temp.size() ; m++)nums[l+m]=temp[m];
}
void merge_sort(vector<int>&nums , int l , int h){
    if(l<h){
        int mid=(l+h)/2;
        merge_sort(nums , l , mid);
        merge_sort(nums , mid+1 , h);
        merge(nums , l , mid , h);
    }
}
int main(){
    vector<int>nums={9,8,76,5,4,3,2,1};
    merge_sort(nums , 0 , nums.size()-1);
    for(auto& el : nums)cout<<el<<" ";
    return 0;
}