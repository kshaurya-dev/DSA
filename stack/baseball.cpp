//LEETCODE 682 - BASEBALL GAME 
// + -> add previous scores , D -> Double the last score , 'C' -> remove the last score
#include <bits/stdc++.h>
using namespace std;
int score(vector<string>operations){
    stack<int>stack;
    int total=0;
    for(auto& op:operations){
        cout<<op<<'\n';
        if(op=="+"){
            int num1=stack.top();
            stack.pop();
            int num2=stack.top();
            stack.pop();
            total+=num1+num2;
            stack.push(num2);
            stack.push(num1);
            stack.push(num1+num2);
        }
        else if(op=="D"){
            stack.push(stack.top()*2);
            total+=stack.top();
        }
        else if(op=="C"){
            total-=stack.top();
            stack.pop();}
        else {
            total+=stoi(op);
            stack.push(stoi(op));}
        cout<<"total="<<total<<'\n';
    }
    return total;
}
int main(){
    vector<string>operations={"1","C"};
    cout<<"ANSWER = "<<score(operations);
    return 0;

}