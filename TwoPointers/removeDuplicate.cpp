/*Algo to remove duplicates in a sorted array. you can keep k reptitions
-----------2 POINTERS---------------- */
#include<bits/stdc++.h>
int main(){
    std::vector<int>nums={1,1,2,3,4,5,6,7,8};
    int i =1;
    int k=4;//max repitions allowed
    for(int j=1 ; j<nums.size();++j){
        if(i < k || nums[j]!=nums[i-k]){
            nums[i]=nums[j];
            i++;
        }
    }
    for(int m=0 ; m<i ; ++m){
        std::cout<<nums[m]<<'-';
    }
    return 0;
}