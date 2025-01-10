//check if 2 strings are anagrams , i.e - contain same number of alphabets 
// ex- cat,tac , act 
//hash map approach
#include<bits/stdc++.h>
int main(){
    std::string s="cat";
    std::string t="act";
    if(s.size() != t.size()){
        std::cout<<"false";
        return 0;}
    else{
        std::map<char,int>mapS;
        std::map<char,int>mapT;
        for(int i=0 ; i<s.size() ; i++){
            mapS[s[i]]++;
            mapT[t[i]]++;
        }
        for(int i =0 ; i<s.size() ; i++){
            if (mapS[s[i]]!=mapT[s[i]]){
                std::cout<<"false";
                return 0;}}
    }
    std::cout<<"true";
    return 0;
    /*the question is very simple , we make two maps counting characters
    and storing counts . next we just make sure if the character in the two
    exist and also of same count*/
}