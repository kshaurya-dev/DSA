/*Monotonic stack - or a stack in which elements are pushed in either increasing or
decreasing order*/

#include<bits/stdc++.h>

int main(){

    std::vector<int>nums={3,4,7,8,1,35,67,8,0};
    std::vector<int>answer(nums.size() , -1);
    std::stack<int>stk;

    for(int i =0 ; i<nums.size() ; i++){
        while(!stk.empty() && nums[i]>nums[stk.top()]){
            answer[stk.top()]=nums[i];
            stk.pop();
        }
        stk.push(i);
    }
    for(auto& el:answer){
        std::cout<<el<<' ';
    }

    return 0;
}