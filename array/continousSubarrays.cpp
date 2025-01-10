/*Find all subarrays containing only a single element k*/
/*Simple array question with an easy yet tricky logic*/
#include<bits/stdc++.h>
int main(){
    std::vector<int>nums={1,1,2,2,2,0,1,1,0,0,0,5,5,5,5};
    int k{5};
    int count{0};
    int continous_count{0};
    for(auto& num:nums){
        if(num==k){
            ++continous_count;
            count+=continous_count;
        }
        else{
            continous_count=0;
        }
    }
    /*if we encounter k , we increase continous_count, if not reduce it to 0;
    now why add it everytime to count?-
    --> Every occurence of k is a subarray itslef.
    --> If we have, say n continous occurences of k till an index i , then --
    Number of subarrays= (no. of continous occurences of before i) + 1
    ex~ we have [1,1,1,1] , no. of subarrays = 3+1=4
    we add this everytime to count
    */
    std::cout<<"SUBARRAYS CONTAINING ONLY "<<k<<" = "<<count;
    return 0;
}
