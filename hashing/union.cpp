//find intersection of two arrays
//basically return the common values , no repition
//hashset approach
#include<iostream>
#include<vector>
#include<set>

int main(){

    int nums1[3]={4,9,5};
    int nums2[5]={9,4,9,8,4};
    std::vector<int>ans;
    std::set<int>hashset;
    for(int i =0 ; i<3 ; i++){
        hashset.insert(nums1[i]);
    }
    for(int i =0 ; i<5 ; i++){
        if(hashset.find(nums2[i])!=hashset.end()){
            ans.emplace_back(nums2[i]);
            hashset.erase(nums2[i]);
        }
    }
    for(auto& i : ans){
            std::cout<<i<<' ';
        }
    return 0;
}