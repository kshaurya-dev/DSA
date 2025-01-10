//determine number of substrings with all a,b,c as characters
#include<bits/stdc++.h>
int main(){
    std::string s="bcaabcabbbbbbcabcbababbabacccababbabbabbacacaccaccaccacbbabbabbababbcbcbcbc";
    int res=0;
    /*BRUTE FORCE - Simple generate all substrings the way we usually do 
    then check if all the 3 chars are there , and one interesting thing to note
    lets say at j=3 , ypu found all three chars , then all the remaining 
    iterations of j , which eventually will generate the remaining substrings
    for that value of j , will also contain those 3 elements (think about it,
    its easy) , use a hash for keeping track of a,b,c

    for(int i =0 ; i<s.size() ; i++){
        std::vector<int>hash(3,0);
        for(int j=i ; j<s.size() ; j++){
            hash[s[j]-'a']=1;
            if(hash[0]+hash[1]+hash[2]==3){
                res+=s.size()-j;
                break;
            }
        }
    }*/
   /* So the OPTIMAL , it is quite like the other sliding window ones I did,
   this one involves storing frequencies of a,b,c too . so we add right pointer
   to the hash , increasing freq , the moment we have all a,b,c  in hash 
   we increase hash and all substrings after that (res+=s.size()-right) , so 
   now we gotta shrink the window (move left pointer ) , so we decrease it 
   until the same condition - are a,b,c still there? - is true;*/
   
  int left{0};
  std::vector<int>hash(3,0);
  for(int right=0 ; right<s.size() ; ++right){
    hash[s[right]-'a']++;
    while(hash[0]!=0 && hash[1]!=0 && hash[2]!=0){
    
        res+=s.size()-right;
        hash[s[left]-'a']--;
        left++;
    }
    /*so this while loop, it is invoked the moment we find all 3 , and it adds 
    to res, afterwards it tries to shrink the window , as we gotta find all 
    substringsor subarrays , so it shrinks by subtracting it and moving left , adding more
    substrings to the equation  until we no longer have all 3 in our window ,
    when while loop breaks it says - HEY I HAVE COUNTED ALL POSSIBLE SUBSTRINGS
    IN THIS WINDOW TILL RIGHT , NOW I HAVE NO SUBSTRINGS WITH ALL 3 , YOU
    CAN INCREMENT RIGHT AND EXPAND THE WINDOW , AND I'LL CHECK AGAIN!*/
  }
    std::cout<<res;
    return 0;

}