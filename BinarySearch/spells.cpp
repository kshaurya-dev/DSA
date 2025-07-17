//LEETCODE 2300

#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>spells={5,1,3};
    vector<int>potions={1,2,3,4,5};
    int success=7;
    sort(potions.begin() , potions.end());
    vector<int>pairs;
    for(auto& spell:spells){
        int low=0;
        int high=potions.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long prod=potions[mid]*spell;
            if(prod>=success)high=mid-1;
            else low=mid+1;
        }
        pairs.emplace_back(potions.size()-low);
    }
    for(auto& el:pairs)cout<<el<<' ';
    return 0;
}