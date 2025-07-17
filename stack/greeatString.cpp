#include <bits/stdc++.h>//LEETCODE 1544 
/*if two adjacent chars are chota bhai- bada bhai pairs , remove'em ! e.g => aA , Ss , Gg*/
using namespace std;
void displayStack(stack<char> s) {
    vector<char>arr(s.size());
    int i=0;
    while (!s.empty()) {
        arr[i++]=s.top(),s.pop();
    }
    cout << "Stack : \n";
    for(int i=0; i<arr.size(); ++i){
        cout<<"| "<<arr[i]<<" |\n";
    };
    cout << endl;
}
int main(){
    std::stack<char>stack;
    string s="NAanorRoOrROwnTNW";
    for(auto& ch:s){
        cout<<ch<<"\n";
        if(!stack.empty() && (ch+32==stack.top()||ch-32==stack.top())) stack.pop();
        else stack.push(ch);
        displayStack(stack);
    }
    string res="";
    int n=stack.size();
    while(n--) res+=stack.top(),stack.pop();
    reverse(res.begin() , res.end());
    cout<<res;
return 0;
}