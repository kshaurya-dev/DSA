/* An array of size n consists of elements in range of [1,n] only
Elements appear once or twice only , find duplicates
NEGATING/MARKING TECHNIQUE*/
#include<bits/stdc++.h>
int main(){
    std::vector<int>nums={1,2,3,4,5,1,2,3,4,5};
    int found=0;
    for(int i=0 ; i<nums.size() ; ++i){
        int index=abs(nums[i])-1;
        if(nums[index]<0){
            std::cout<<abs(nums[index])<<' ';
            found=1;}
        else nums[index]=-nums[index];
    }
    if(!found)std::cout<<"Duplicates Not Found !!";
    /* Again we access each index via nums[i] as nums[i] is  in range of[1,n],
    so every nums[i] is a valid index in nums , we negate them one by one,
    we check if the index nums[i] is pointing at is already negative which means
    index has already been pointed at before hand - its clearly a duplicate*/
    return 0;
}
