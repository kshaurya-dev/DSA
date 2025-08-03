/*LEETCODE 1190 - reverse between parentheses , basically between every pair of 
parenthesis , reverse the string (u(love)i)=iloveu*/
#include<bits/stdc++.h>
using namespace std;
/*alright interesting question ! well between every parenthesis ,string has to be reversed ,
well stack has the property that when you insert elements into it and then take them out , they
are reversed ! so gotta use that property !
 steps - 
 1) insert elements to the stack
 2) the moment you find ')' , pop and until '('
 3) now insert them back in the order they were popped , basically insert reversed elements ,
 the core idea is that we are reversing between valid parenthesis and inserting the reversed 
 order ensures that the next time if they ever become part of another nested parenthesis ,
 they will be reversed again !!!
 
 interestingly , i knew the reverse property of stacks , but never really cared for it , and 
 being dumb , i was literally reversing strings after popping !
 and also remember that magic trick at the end , where res = stack.top() + res , literally
 doesn't cause the string to be reversed , even though they were just popped from a stack!*/

 
int main(){
    string s = "(ed(et(oc))el)";
    stack<char>stack;
    for(auto & ch : s){
        if(ch==')'){
            vector<char>temp;
            while(stack.top()!='('){
                temp.emplace_back(stack.top());
                stack.pop();
            }
            stack.pop();
            for(auto& c : temp)stack.push(c);
        }
        else stack.push(ch);
    }
    string res="";
    while(!stack.empty()){
        res = stack.top() + res;
        stack.pop();
    }
    cout<<res;
    return 0;
}