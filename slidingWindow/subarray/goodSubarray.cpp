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
        hash[nums[right]]++;
        while(hash[nums[right]]>2){
            hash[nums[left++]]--;
        }
        res=max(res,right-left+1);
    }
    cout<<res;
    return 0;
}