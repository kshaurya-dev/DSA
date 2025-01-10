//find if the array contains duplicate numbers
//hashset approach
#include<bits/stdc++.h>
int main(){
    std::set<int>hashset;
    std::vector<int>nums={1,2,3,1};
    int n= nums.size();

    
    for(int i =0 ; i< n ; i++){
        if(hashset.find(nums[i])!=hashset.end()){
            std::cout<<"duplicate found ! : ";
            return 0;
        }
        hashset.insert(nums[i]);
    }
    std::cout<<"No duplicates !";
    /*we create a set , but before populating it with elements of nums
    , we check if the element of nums the iteration is currently at 
    , already exists in the set , if does we return true immediately*/
    return 0;
}