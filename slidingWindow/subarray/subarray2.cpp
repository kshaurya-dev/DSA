//LEETCODE 2841
#include<bits/stdc++.h>
int main(){
    std::vector<int>nums={1,2,2};
    int k{2};
    int m{2};
    int sum=0;
        int res=0;
        std::map<int,int>hash;
        //initial window
        for(int i=0 ; i<k ; ++i){
            sum+=nums[i];
            hash[nums[i]]++;
            }
        if(hash.size()>=m)res=std::max(res , sum);
        //sliding the window
        for(int i=k ; i<nums.size() ; ++i){
            std::cout<<"map :  ";
            for(auto& pair : hash){
                std::cout<<pair.first<<'-'<<pair.second<<" , ";
            }
            std::cout<<'\n';
            sum=sum+nums[i] - nums[i-k];
            std::cout<<sum;
             std::cout<<'\n';
            if(--hash[nums[i-k]]==0)hash.erase(nums[i-k]);
            hash[nums[i]]++;
            if(hash.size()>=m){
                std::cout<<"Found a subarray : ";
                for(auto& pair:hash) std::cout<<pair.first<<'-'<<pair.second<<" , ";
                std::cout<<'\n';
                res=std::max(res , sum);}
        }
        std::cout<<res;
    return 0;
}