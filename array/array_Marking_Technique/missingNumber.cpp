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
