/*Find sum of a subarray */
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>nums={1,2,3,4,5};
    vector<int>prefix(nums.size()+1);
    int sum=0;
    prefix[0]=0;
    for(int i =0 ; i<nums.size() ; i++){
        sum+=nums[i];
        prefix[i+1]=sum;
    }
    cout<<"subarray sum to calculate ? gimme two indices - ";
    int i,j;
    cin>>i>>j;
    cout<<"subarray sub is : "<<prefix[j+1]-prefix[i];
    return 0;
}