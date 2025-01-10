//LEETCODE 2958
#include<bits/stdc++.h>
using namespace std;
int main(){
    std::vector<int>nums={5,5,5,5,5,5,5};
    unordered_map<int,int>hash;
    int left=0;
    int k =2;
    int res=0;
    for(int right =0 ; right<nums.size() ; ++right){
        cout<<"window : ";
        for(int i=left ; i<=right ; ++i){
            cout<<nums[i]<<' ';}
        cout<<'\n';
        hash[nums[right]]++;
        std::cout<<"map :  ";
            for(auto& pair : hash){
                std::cout<<pair.first<<'-'<<pair.second<<" , ";
            }
            std::cout<<'\n';
        while(hash[nums[right]]>2){
            hash[nums[left++]]--;}
        cout<<"subarray : ";
        for(int i=left ; i<=right ; ++i){
            cout<<nums[i]<<' ';}
        cout<<'\n';
        res=max(res,right-left+1);
    }
    cout<<res;
    return 0;
}