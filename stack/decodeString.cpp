/*LEETCODE 394 - DECODE STRING 
a string will given of form - k["string"] , you gotta return k X "string"*/
#include <bits/stdc++.h>
using namespace std;
/*
inarguably the best stack problem I have done !
well i made two stacks , one for integer , second for brackets and strings , the moment
i encounter a closing bracket , I pop and build the string up until I encounter a opening bracket
,then i build the resultant string multiplying it integer_stack.top() times and push it
to the string_stack , at the end I empty the string_stack , building all strings together ! */

/*ok a very subtle detail , i was doing temp += stack.top() and then after building string , i 
had to reverse the string , but if i just do temp = stack.top() + temp , no need to fucking 
reverse , MOTHAFUCKA !*/
int main(){
    string s = "2[abc]3[cd]ef";
    /*stack<int>stack1;
    stack<string>stack2;
    int i =0;
    well this is the og soultion , that i did by myslef via stacks ,but could  be done easily
    by a single stack
    while(i<s.size()){
        char ch = s[i];
        if(isdigit(ch)){
            int num=0;
            while(i<s.size() && isdigit(s[i]) ){
                num = num*10 + (s[i]-'0');
                i++;
            }
            stack1.push(num);
        }
        else if(ch==']'){
            string temp="";
            while(!stack2.empty() && stack2.top()!="["){
                temp+=stack2.top();
                stack2.pop();
            }
            stack2.pop();
            string temp2="";
            for(int i = 0 ; i<stack1.top() ; i++) temp2+=temp;
            stack1.pop();
            stack2.push(temp2);
        }
        else{
            string str(1,ch);
            stack2.push(str);
        }
        i++;
    }
    string res="";
    while(!stack2.empty()){
        if(stack2.top()!="]")res+=stack2.top();
        stack2.pop();
    }
    std::reverse(res.begin() , res.end());
    cout<<res;
    */
    //single stack solution
    stack<string>stack;
    for(auto& c : s){
        string ch(1, c);
        if(ch!="]")stack.push(ch);
        else{
            string substr=""; //build substring
            while(stack.top()!="[")substr=stack.top()+substr, stack.pop();
            stack.pop();     //remove the "["
            string k ="";    //build the integer k
            while(!stack.empty() && isdigit(stack.top()[0]))k=stack.top()+k , stack.pop();
            string temp="";  //push k * substr
            for( int i =0 ; i<stoi(k) ; i++)temp += substr;
            stack.push(temp);
        }
    }
    string res="";
    while(!stack.empty())res = stack.top() + res , stack.pop();
    cout<<res;
    return 0;
}