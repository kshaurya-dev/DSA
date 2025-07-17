//implement queue using stack
//implement stack using queue
#include<bits/stdc++.h>
using namespace std;
class Queue{
    public:
    stack<int>stack;
    void push(int x){
        stack.push(x);
        cout<<"inserted = "<<x<<'\n';
    }
    void pop(){
        int n=stack.size();
        vector<int>temp(stack.size());
        for(int i =0 ; i<temp.size(); ++i){
            temp[i]=stack.top(),stack.pop();
        }
        for(int i=temp.size()-2 ; i>=0 ;--i)stack.push(temp[i]);
        cout<<"removed =  "<<temp[temp.size()-1]<<'\n';
    }
    void show(){
        std::stack<int>temp=stack;
        int arr[temp.size()];
        for(int i=0 ; i<stack.size() ; ++i){
            arr[i]=temp.top(),temp.pop();
        }
        for(int i=0 ; i<stack.size() ; ++i){
           cout<<arr[stack.size()-i-1]<<" ";
        }
        cout<<'\n';
    }
    int size(){
        return stack.size();
    }
    bool empty(){
        return stack.empty();
    }
    int top(){
        std::stack<int>temp=stack;
        int k=temp.size();
        while(k>1) temp.pop(),k--;
        return temp.top();
    }
    int back(){
        return stack.top();
    }
};
int main(){
    Queue que;
    que.push(1);
    que.push(2);
    que.push(3);
    que.push(4);
    que.push(5);
    que.show();
    que.pop();
    que.pop();
    que.show();
    cout<<"front="<<que.top();
    cout<<"back="<<que.back();
    return 0;
}