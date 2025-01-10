/*given an array return an array containing product of 
each index except itself*/
#include<bits/stdc++.h>
int main(){
    std::vector<int>nums={1,2,3,4,5};
    std::vector<int>leftProd(5);
    std::vector<int>rightProd(5);
    //first we calculate right product of each element
    int product=1;
    for(int i=0 ; i<5 ; i++){
        leftProd[i]=product;
        product*=nums[i];
    }
    //next we calculate left product of each element
    product=1;
    for(int i=4 ; i>=0 ; i--){
        rightProd[i]=product;
        product*=nums[i];
    }
    //now we multiply the left and right products
    for(int i =0 ; i<5 ; i++){
        nums[i]=leftProd[i]*rightProd[i];
        std::cout<<nums[i]<<' ';
    }
    return 0;
}