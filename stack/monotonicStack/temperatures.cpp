#include <bits/stdc++.h>//LEETCODE 439
/*after how many days  the next warmer day will occur*/
using namespace std;
int main(){
    vector<int> temp={73,74,75,71,69,72,76,73};
    stack<int>stack;
    vector<int>res(temp.size(),0);
    int popped=0;
    for(int i =0 ; i<temp.size() ; i++){
        cout<<"temperature : "<<temp[i]<<'\n';
        cout<<"stack:\n";
        std::stack<int>tempo=stack;
        while(!tempo.empty()){
            cout<<temp[tempo.top()]<<'\n';
            tempo.pop();
        }
        while(!stack.empty() && temp[i]>temp[stack.top()]){
            res[stack.top()]=i-stack.top();
            stack.pop();
        }
        stack.push(i);
        
        }
    for(auto& el:res)cout<<el<<',';
    return 0;
}