/*Given an integer array nums and an integer k, return true if there 
are two distinct indices i and j in the array such that nums[i] == nums[j]
 and abs(i - j) <= k.*/
 //hashmap approach.....
 #include<bits/stdc++.h>
 int main(){
    int k=3;
    std::vector<int>nums={1,0,1,1};
    std::unordered_map<int,int>hash;
    int n = nums.size();
    for(int i =0 ; i<n ; i++){
        if(hash.find(nums[i])!=hash.end()){
            if(abs(hash[nums[i]]-i)<=k){
                std::cout<<"true";
                return 0;}  
        }
        hash[nums[i]]=i;
    }
    std::cout<<"false";
    return 0;
 }
 //.......................................................
 /*we use a hashmap that stores element and their index , just like contains 
 duplicate 1 , where we used a set , here before adding a key in map
 i check if the element already exists in the map , if it does I check the 
 abs(i-j) and return . if these conditions are false , then only I add the 
 element as key */