/*Basic mathematical expression calculator using stack*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    string expression="5*5*5-65/13+100+800-4949*56";
    map<char,int>precedence=
         { {'+', 1},
          {'-', 1},
          {'*', 2},
          {'/', 2} } ;
    stack<char>op;
    stack<float>nums;
    for(int i=0 ; i<expression.size() ; ++i){
        float num=0;
        if (isspace(expression[i])) continue;
        if(isdigit(expression[i])){
            while(i<expression.size() && isdigit(expression[i])){
                num=num*10 + (expression[i]-'0');
                ++i;
            }
            nums.push(num);
            --i;
        }
        else{
            while(!op.empty() && precedence[expression[i]]<=precedence[op.top()]){

                float num2=nums.top();nums.pop();
                float num1=nums.top();nums.pop();
                float result;

                if (op.top() == '+') result = num1 + num2;
                else if (op.top() == '-') result = num1 - num2;
                else if (op.top()== '*') result = num1 * num2;
                else result = num1 / num2;
                nums.push(result);
                op.pop();
                }
                op.push(expression[i]);
        } 
    }
    while(!op.empty()){
        float num2=nums.top();nums.pop();
        float num1=nums.top();nums.pop();
        char oper=op.top();op.pop();
        if(oper=='+')nums.push(num1+num2);
        else if(oper=='-')nums.push(num1-num2);
        else if(oper=='*')nums.push(num1*num2);
        else nums.push(num1/num2);
    }
    cout<<"ANSWER = "<<nums.top();
    return 0;
}
