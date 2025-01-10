//Find the subarray with largest sum of size k

#include <iostream>

int main(){
    int arr[6]={1,6,3,10,99,6};
    int k{6};
    int max{0};

    //calculating max for first k sized subarray

    for(int i =0 ; i<k ; i++){max+=arr[i];}

    //iterating over array and updating max

    int left{0};
    int sum{max};
    
    for (int i{k} ; i<6 ; ++i){
        sum= sum-arr[left]+arr[i];
        left++;
        max=std::max(max,sum);
    }

    std::cout<<max;
    return 0;
}