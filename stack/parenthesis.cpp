#include <bits/stdc++.h>//LEETCODE 20 - VALID PARENTHESIS  , return if brackets
// make sense or not
using namespace std;
bool check(string s){
    std::stack<char>stk;
    map<char,char>map={
        {')','('},
        {'}','{'},
        {']','['}
    };/*the idea is to push only and only  starting brackets and as soon as 
    matching closing bracket is found , pop it , else its obviously not valid.
    since the opening bracket that has just been encountered(aka last in) has
    to be closed first ( first out ) , we use a stack*/
    for(char ch:s){
        stack<char>temp = stk;
        cout<<"STACK = ";
        while (!temp.empty()) {
            std::cout << temp.top() << " ";
            temp.pop();
            }
        cout<<"character="<<ch;
        cout<<'\n';
        if(map.find(ch)!=map.end()){
            if(stk.empty())return false;
            else if (stk.top()!=map[ch])return false;
            else stk.pop();
        }
        else stk.push(ch);  
    }
    return stk.empty();
}
int main(){
    string s="[{[()[()]}]";
    cout<<check(s);
    return 0;

}