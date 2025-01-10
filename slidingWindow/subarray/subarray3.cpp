#include<bits/stdc++.h>
using namespace std;
int main(){
    std::vector<int>nums={12,28,83,4,25,26,25,2,25,25,25,12};
    int left=0;
        int sum=0;
        int res=nums.size();
        int target=213;
        int found=0;
        for(int right=0 ; right<nums.size() ; ++right){
            sum+=nums[right];
            while(sum>=target){
                /*if you enter this while loop , we have the possible candidate for being the 
                smallest subarray ( obviously since while loop executes when our very condition
                is satisfied. )*/
                cout<<" shrinking the subarray : ";
                for(int i=left ; i<=right ; ++i){
                    cout<<nums[i]<<' ';
                }
                /**/
                cout<<" sum is:" <<sum<<" , length is "<<right-left+1<<'\n';
                res=min(res , right-left+1);
                found=1;
                sum-=nums[left];
                ++left;
            }
            if(sum>=target){
                cout<<"subarray : ";
                for(int i=left ; i<=right ; ++i){
                    cout<<nums[i]<<' ';
                }
                cout<<'\n';
                res=min(res , right-left+1);
                found=1;
                }
        }
        if(found)cout<<res;
        else cout<<0;
    return 0;
}