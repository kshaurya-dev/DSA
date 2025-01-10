/*You have to separate 1s and 0s in an array and return number of swaps
 needed , only adjacent swapps are allowed*/
 #include<bits/stdc++.h>
 int main(){
    std::vector<int>nums={1,1,1,1,1,0,1,1,1,1,0,0,0,1,1,0};
    int last_zero=0;
    int count=0;
    for(int i =0 ; i<nums.size() ; ++i){
        if(nums[i]==0){
            count+=(i-last_zero);
            last_zero++;
            }
    }
    std::cout<<count;
    return 0;
    /*I find a zero , rather than actually going through the struggle to swap it right to 
    the begginning , i just calaculate how many swaps would be needed if I did....which is
    just i-last_zero ....then the question is simple two pointer question!*/
 }