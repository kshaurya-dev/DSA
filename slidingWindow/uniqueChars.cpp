/* LEETCODE:3 -Find the length of the longest subarray with unique elements*/
#include<bits/stdc++.h>
int main(){
    std::string s="tmmzuxt";
    /*Brute force will be to check each and every subarray using a hash set to 
    check for repeating chars
    A better solution is a sliding window , whihc shrink till the set has unique
    elements*/
    /*int left=0;
    int length=0;
    std::set<char>hash;
    for(int right=0; right<s.size() ; ++right){
        char ch=s[right];
        while(hash.find(ch)!=hash.end()){
            hash.erase(s[left]);
            ++left;
        }
        hash.insert(ch);
        length=std::max(length, right-left+1);
    }
    std::cout<<length;


    /*oi oi oi , did ya see what we doin' mate ? shrinking window using a while loop
    until we have unique valued substring , my question to you is when does 
    this happen?
    ya ya ya - when we are past the location where the el(which we just found out 
    has appeared).. last appeared.....
    so why using a fooking while loop to go to that index ?? 
    just map the index with the element , and jump straight to it , when it is
    found again.. THIS IS THE OPTIMAL SOLUTION*/
    std::map<char,int>hash;
    int left=0;
    int length=0;
    for(int right=0 ; right<s.size() ; ++right){
        char ch=s[right];
        if(hash.find(ch)!=hash.end()){
            left=std::max(hash[ch]+1,left);
        }
        hash[ch]=right;
        length=std::max(length,right-left+1);
    }
    std::cout<<length;
    return 0;

}