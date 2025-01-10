#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>nums={1,3,2,3,3};
    int k=2;
    int el=0;
        for(auto& num:nums) el=max(el,num);
        int count=0;
        int res=0;
        for(int i =0 ; i<nums.size() ; ++i){
            if(nums[i]==el)count++;
            cout<<"res:"<<res<<'\n';
            if(count>=k)res+=i+1;;
        }
       cout<<res; 
    
    return 0;
}