/*Your'e given an array , find the max length subarray with exactly 
and only k distinct elements*/
#include<bits/stdc++.h>
int main(){
    std::vector<int>nums={3,3,3,1,2,1,1,2,3,3,4};
    int k{2};
    int left{0};
    int right{0};
    int res{0};

/*BRUTE FORCE-Simply generate all possible subarrays , 
to check distinct element=k , use set.size()
    for(int i =0 ; i<nums.size() ; i++){
        std::set<int>set;
        for(int j=i ; j<nums.size() ; j++){
            set.insert(nums[j]);
            if(set.size()>k){
                break;
            }
            res=std::max(res,j-i+1);
        }
    }
    std::cout<<res;
    return 0;*/
/*now the optimal approach is very iggly-wiggly. So we use a map to store
the elements and also their frequency this time ....so take right pointer ,
add the element to map , until our map's size is more than k...now 
we gotta reduce size of map until it is k ....so keep removing element 
which is at left until it is completely removed */
    std::unordered_map<int,int>map;
    while(right<nums.size()){
        map[nums[right]]++;
        while(map.size()>k){
            map[nums[left]]--;
            if(map[nums[left]]==0){
                map.erase(nums[left]);
            }
/*so this while loop confused me a lot .... but it works by removing value 
at left until its frequency is zero , lets visualise it -
say the subarray is - [1,2,1,2,1,3] ,when right goes at the end , map's size
is more than two, so we move left pointer , decreasig 1's frequency , then 2's
frequency , and then so on .... the very moment left pointers frequency goes 
0 - we erase it , thus map size is now 2 !*/
            left++;
        }
        res=std::max(res,right-left+1);
        right++;
    }
    std::cout<<res;
    return 0;
}