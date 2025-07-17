//implement stack using queue
#include<bits/stdc++.h>
using namespace std;
class Stack{
    public:
    queue<int>que;
    void push(int x){
        que.push(x);
        cout<<"inserted = "<<x<<'\n';
    }
    void pop(){
        int n=que.size();
        while(--n){
            que.push(que.front());
            que.pop();
        }
        cout<<"removed =  "<<que.front()<<'\n';
        que.pop();
    }
    void show(){
        queue<int>temp=que;
        int arr[temp.size()];
        for(int i=0 ; i<que.size() ; ++i){
            arr[i]=temp.front(),temp.pop();
        }
        for(int i=0 ; i<que.size() ; ++i){
           cout<<"| "<<arr[que.size()-i-1]<<" |\n";
        };
    }
    int size(){
        return que.size();
    }
    bool empty(){
        return que.empty();
    }
    int top(){
        return que.back();
    }
};
int main(){
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.show();
    stack.pop();
    stack.show();
    stack.pop();
    stack.show();
    stack.pop();
    stack.show();
    stack.push(8);
    stack.show();
    return 0;
}