/*for an array of only 1 and 0 as elements ,return the max number of 
consecutive zeroes after flipping any k zeroes.*/

#include<bits/stdc++.h>
int main(){
    std::vector<int>nums={1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1};
    int k{2};
/*So this is a trademark sliding window question with two pointers
as you can think of it as MAX LENGTH SUBARRAY WITH K ZEROES . once you get this
this question is scorched earth!!*/
    int left{0};
    int right{0};
    int zeroCount{0};
    int res{0};
/*when I first attempted this I spent 2 hours trying to figure out how to count
the 1s , well that what we need to find , right ?. but the approach involving
counting of 0s instead is much easier. 
so take two pointers  move right as far as you can , counting zeroes , 
the moment zeroCount goes more than k , move left furthur  until zeroes are 
again in thier damn limit , count length everytime.*/
    while(right<nums.size()){
        if(nums[right]==0)++zeroCount;
        while(zeroCount>k){
            if(nums[left]==0){
                --zeroCount;
            }
            ++left;
        }
        res=std::max(res,right-left+1);
        ++right;
    }
    std::cout<<res;
    return 0;

}