/*LEETCODE 150 - Evaulate reverse polish notation*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<string>tokens={"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    stack<int>stack;
    for(auto& token : tokens ){
        if(token=="+" || token=="-"||token=="*"||token=="/"){
            int num1=stack.top();
            stack.pop();
            int num2=stack.top();
            stack.pop();
            if(token=="+")stack.push(num1+num2);
            else if(token=="-")stack.push(num2-num1);
            else if(token=="*")stack.push(num2*num1);
            else stack.push(num2/num1);
        }
        else stack.push(stoi(token));
    }
    cout<<stack.top();
    return 0;
}
