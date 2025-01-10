//stack implementation using arrays
#include<bits/stdc++.h>
class Stack{
    private:
    static const int N{10};
    int stk[N];
    int top;
    public:
    Stack():top(-1){}

    void push(int el){
        if(top==N-1){
            std::cout<<"STACK FULL !!";
            return ;
        }
        stk[++top]=el;
    }

    void pop(){
        if(top==-1){
            std::cout<<"STACK EMPTY !";
            return;
        }
        --top;
    }
    void display(){
        if(top==-1){
            std::cout<<"STACK EMPTY !";
            return;
        }
        for(int i=top ; i>=0 ; --i){
            std::cout<<stk[i]<<'\n';
        }
    }
    void isEmpty(){
        if(top==-1)std::cout<<"STACK EMPTY"<<'\n';
        else std::cout<<"NOT EMPTY"<<'\n';

    }
    bool isFull(){
        if(top==N-1)return true;
        return false;
    }


};
int main(){
    Stack stk;
    stk.isEmpty();
    stk.push(45);
    stk.push(345);
    stk.display();
    stk.pop();
    stk.display();
    return 0;

}