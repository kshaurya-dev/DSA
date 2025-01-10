//for an array find the two distinct elements which equal to target
//hashmap approach
#include<bits/stdc++.h>
int main(){
    std::vector<int>nums={3,4,2};
    int n=nums.size();
    int target=6;
    /*why the hashset approach doesn't work? the thought process is to the point
    ,we make a set populated with elements of num , if nums[i]-target exists
    in the hashset , nums[i] and nums[i]-target are the two elements.
    but this returns the numbers not their indices and also the same number
    can return twice if nums[i]+nums[i]==target /// hence hashmap approach is
    optimal.
    std::set<int>set;
    for(int i =0 ; i<nums.size() ; i++){
            set.insert(nums[i]);
            }
    for(int i=0 ; i<nums.size() ; i++){
        if(set.find(target-nums[i])!=set.end())
        {
           std::cout<<nums[i]<<target-nums[i];
        }
        }*/

//.....................................................................................
std::unordered_map<int , int>hashmap;
for(int i =0 ; i<n ; i++){
    if (hashmap.find(target-nums[i])!=hashmap.end()){
        std::cout<< i <<'-'<< hashmap[target-nums[i]];
    }
    hashmap[nums[i]]=i;
}
/*basically we make a hashmap instead of a set ,it stores values as well
as thier indices, but before adding the element into map , we check if 
target-nums[i] already exists in it , clearly these two are my output*/

return 0;
}