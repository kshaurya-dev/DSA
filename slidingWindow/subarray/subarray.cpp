//LEETCODE 2461
#include<bits/stdc++.h>
int main(){
    std::vector<int>nums={3,3,5,5,3,3,1,1,4,2,5,1};
    int k{4};
    int res=0;
        std::unordered_map<int,int>hash;
        int sum=0;
        int flag=1;
        for(int i =0 ; i<k ; ++i){
            sum+=nums[i];
            hash[nums[i]]++;
        }
        if(hash.size()==k) res=std::max(res,sum);
        for(int i=k ; i<nums.size() ; ++i){
            std::cout<<"map :  ";
            for(auto& pair : hash){
                std::cout<<pair.first<<'-'<<pair.second<<" , ";
            }
            std::cout<<'\n';
            sum=sum-nums[i-k];
            if(--hash[nums[i-k]]==0)hash.erase(nums[i-k]);
            sum+=nums[i];
            hash[nums[i]]++;
            if(hash.size()==k){
                std::cout<<"Found a subarray : ";
                for(auto& pair:hash) std::cout<<pair.first<<'-'<<pair.second<<" , ";
                std::cout<<'\n';
                res=std::max(res , sum);}
        }
       std::cout<<res;
    return 0;
    }