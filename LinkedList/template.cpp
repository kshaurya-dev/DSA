#include<bits/stdc++.h>
using namespace std;
class Node{
        public:
        int data;
        Node* next;
        public:
        Node(){
            data=0;
            next=NULL;
        }
        Node(int data1 , Node* next1){
            data=data1;
            next=next1;
        }
        public:
        Node(int data1){
            data=data1;
            next=NULL;
        }
    };
Node* convert(vector<int>&nums){
    Node* head=new Node(nums[0]);
    Node* mover=head;
    for(int i =1 ; i<nums.size() ; i++){
        Node* temp=new Node(nums[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;

}
bool exists(Node* head , int el){
    Node* temp=head;
    while(temp){
        if(temp->data==el)return true;
        temp=temp->next;
    }
    return false;
}
int lengthOfLL(Node* head){
    int count=0;
    Node* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
int main(){
    vector<int>arr={1,2,3,4,5,474,57};
    Node* LL= convert(arr);
    //cout<<LL->data<<'\n';
    //cout<<LL->next<<'\n';
//cout<<*(LL->next); this won't work as cout doesn't know how to handle custom classes
    Node* temp=LL;
    while(temp!=NULL){
        cout<<temp->data<<"--"<<temp->next<<'\n';
        temp=temp->next;
    }
    cout<<"Length of LL is : "<<lengthOfLL(LL)<<'\n';
    cout<<"Does  69 exists in LL ? "<<exists(LL,69);
    return 0;
}
/*1. What is ->?

The -> operator is used in C++ (and other languages like C) to access members
(like variables or functions) of an object through a pointer.

Here’s a simpler breakdown:

    When you have a pointer to an object or structure (like a Node*), 
    you need to use the -> operator to access the fields of that object.
    If you don't have a pointer and are working with an object directly, 
    you'd use the . (dot) operator instead.

    Under the hood, ptr->data is equivalent to (*ptr).data.
    The parentheses are required because *ptr.data 
    would try to dereference the data member, which isn’t what we want.*/
