#ifndef STACK_H
#define STACK_H
#include<iostream>
#include <stdexcept>
template <typename T>
class Stack{
private:
    struct Node{
        T data;
        Node* next;
        Node(T value){//constuctor
            data=value;
            next=nullptr;
        }
    };
    Node* top;
    int length;
public:
    Stack(){
        top=nullptr;
        size=0;
    }
    void push(T value){
        Node* newNode=new Node(value);
        newNode->next=top;
        top=newNode;
        length++;
    }
    void pop(){
        if(isEmpty()){
            throw runtime_error("stack underflow");
        }
        Node* temp = top;
        top=top->next;
        delete temp;
        length--;
    }
    T peek(){
        if(isEmpty()){
            throw runtime_error("stack empty");
        }
        return top->data;
    }
    bool isEmpty() {return top==nullptr;}
    int size(){return length;}
    void print(){
        Node* temp=top;
        cout<<"stack :\n";
        while(temp){
            std::cout<<temp->value<<'\n';
            temp=temp->next;
        }
    }
    ~Stack() {
        while(!isEmpty()){
            pop(); 
        } 
    }
    
};
#endif 