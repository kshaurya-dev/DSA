/*LEETCODE 1002 - find characters which are common in all the words */
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<string>words={"shaumrya","manish","ramtak","ambhay" ,"amyush"};
    vector<int>minfreq(26,INT_MAX);
    for(auto& word : words){
        vector<int>freq(26,0);
        for(auto& ch : word)freq[ch-'a']++;
        for(int i =0 ; i<minfreq.size() ; i++){
            minfreq[i]=std::min(freq[i] , minfreq[i]);
        }
    }
    /*i used a hashtable , idea is to track frequencies , and then track frequencies of characters which 
    were in previous word , can easily be done via hashmap , but i used a hastable cause its faster
    in the start minFreq is initialised to MAX , then  we track the next word's frequecy and take the 
    minimum of global minfreq , the same is repeated for all words
    what happens ? well if lets say we have lullaby - 3 l's , the next word is coming , which has no 
    l's ,  hence minfreq which had 3 l's  , will now have 0 l's as we assign the minimum only!*/
    vector<string>res;
    for(int i =0 ; i<minfreq.size() ; i++){
        int q=minfreq[i];
        while(q--)res.emplace_back(string(1,'a'+i));
    }
    for(auto& ch: res)cout<<ch<<' ';
    return 0;
}