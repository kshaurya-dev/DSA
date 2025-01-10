#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>nums={1,0,1,0,1};
    int goal=2;
    int left=0;
    int sum1=0;
    int sum2=0;
    int count1=0;
    int count2=0;
    cout<<"subarrays with sum less than or equal to "<<goal-1<<'\n';
    for(int right=0 ; right<nums.size() ; ++right){
        if(goal==0){
            count1=0;
            cout<<"none\n";
            break;
        }
        sum1+=nums[right];
        while(sum1>goal-1) sum1-=nums[left++];
        for(int i=left ; i<=right ; ++i){
                    cout<<nums[i]<<' ';
                }
                cout<<'\n';
        count1+=right-left+1;
    }
    left=0;
    cout<<"sub arrays with sum less than or equal to "<<goal<<'\n';
    for(int right=0 ; right<nums.size() ; ++right){
            sum2+=nums[right];
            while(sum2>goal) sum2-=nums[left++];
            for(int i=left ; i<=right ; ++i){
                    cout<<nums[i]<<' ';
                }
                cout<<'\n';
            count2+=right-left+1;
        }
       cout<<count2-count1;
    return 0;

}