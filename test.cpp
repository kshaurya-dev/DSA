#include<bits/stdc++.h>
using namespace std;

int main(){
    int l=0;
    string s ="aabacbebebe";
    int res=0;
    map<char , int>hash;
    for(int r=0; r<s.size() ; r++){
        hash[s[r]]=r;
        if(hash.size()>2) {
            int smallest=INT_MAX;
            char to_delete;
            for(auto& pair : hash){
                if(pair.second < smallest){
                    smallest = pair.second;
                    to_delete=pair.first;}
            }
            hash.erase(to_delete);
            l =smallest+1;
        }
        res=std::max( r-l+1 , res);
    }
    cout<<res;
    return 0;
}