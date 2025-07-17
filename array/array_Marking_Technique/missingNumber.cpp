/*Findn the missing number in an array of size n,
containing elements in range of - [1,n]  only.
NEGATING/MARKING INDICES TECHNIQUE    */
#include<bits/stdc++.h>
int main(){
    std::vector<int>nums={5,5,5,5,5};
    for(int i=0 ; i<nums.size() ; ++i){
        int index=abs(nums[i])-1;
        nums[index]=-abs(nums[index]);
    }
    std::vector<int>ans;
    for(int i=0 ; i<nums.size() ; i++){
       if(nums[i]>0)ans.emplace_back(i+1);
    }
    for(int i=0 ; i<ans.size() ; i++){
        std::cout<<ans[i]<<' ';
    }
    if(!ans.size()) std::cout<<"No Missing Number ! ";
    /*Since all elements are in range of [1,N] ,hence each element can be a valid 
    index in nums , since some of them are missin that ofc means some elements must
    appear more than twice. We are negating every index by accessing them via elements
    ,the number  that is missing will never have the index it is refering to be negative
    , so we just search for positive values left in nums  */
    return 0;
}


//leetcode #3 - longest substring without repeating characters
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
which is at left until it is completely removed 
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
0 - we erase it , thus map size is now 2 !
            left++;
        }
        res=std::max(res,right-left+1);
        right++;
    }
    std::cout<<res;
    return 0;
    /*but can we do even better ? well currently we use a map to store which elements we have seen ,
    if key exists , well time to shrink the window ...
    Can you answer why do we have a nested loop ? cause we don't know when did the last occurence happend,
    so window has to be shrink until we again have only one occurence 
    what if we know the last occurence ? what if we store the element's index as its value while making
    a key ? yes ! then whenever a duplicate  is found , we jump straight to one more than the last index!*/
    //THIS TIME LETS USE A HASHTABLE RATHER THAN A MAP


}
