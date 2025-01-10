//in array return top k most frequent elements 
// ex - [1,1,1,2,2,2,3] , k=2 , ans=1,2 ; if k=3 , ans=1,2,3
//hashmap approach

#include<bits/stdc++.h>
int main(){
    std::vector<int>nums={1,1,1,2,2,3};
    int k=2;
    std::map<int,int>map;
    //first we just map count of each element
    for(int i =0 ; i<nums.size() ; i++)map[nums[i]]++;
    /*now we go clever here , since top k means the k elements with highest
    count , we simply make a hash table of count which stores which elements
    have that particular count . so if 2,3 appear four times , the 4th  index
    of our hash table stores 2 and 3 . This has following advantages - 
    1) count is always gonna be postive , so hashtable is possible
    2) The most clever fact is that the hash is actually of size of nums !
    as the frequency of an element can atmost be equal size of array (when
    it is alone in array) obviously !!*/
    std::vector<std::vector<int>>elements(nums.size()+1);
    for(auto& pair:map){
        elements[pair.second].emplace_back(pair.first);
    }
    //now we just iterate backwards in hashtable and return numbers until k
    int m=0;
    for(int i =elements.size()-1 ; i>0 ; --i){
        for(auto& n:elements[i]){
            std::cout<<n<<' ';
            m++;
            if(m==k)return 0;
        }
    }
    return 0;
}