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
    Node(int value){
        data=value;
        next=NULL;
    }
    Node(int value , Node* next1){
        data=value;
        next=next1;
    }
};
Node* convert(vector<int>nums){
    if(nums.size()<=0)return NULL;
    Node* head=new Node(nums[0]);
    Node* mover=head;
    for(int i=1 ; i<nums.size() ; ++i){
        Node* temp =new Node(nums[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
Node* insertAtLoc(Node* head , int position ,int value, int n)
{
    if (head==NULL){
        std::cout<<"List Empty";
        return head;
    }
    else if(position>n){
        std::cout<<"Not enough items in Linked List";
        return head;
    }
    else if(position==1){
        Node* node=new Node(value,head);
        return node;
    }
    else if(position==n){
        Node* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        Node* node = new Node(value,NULL);
        temp->next=node;
        return head;
    }
    Node* temp=head;
    for(int i =0 ; i<position-2 ; ++i){
        temp=temp->next;
    }
    Node* node=new Node(value , temp->next);
    temp->next=node;
    return head;

}
int main(){
    vector<int>nums={2,3,4,578,73737};
    Node* head=convert(nums);
    std::cout<<"OG Linked List:\n";
    Node* temp=head;
    while(temp){
        std::cout<<temp->data<<'\n';
        temp=temp->next;
    }
   std::cout<<"After inserting \n";
   head=insertAtLoc(head , 5 , 56 , nums.size());
   temp=head;
   while(temp){
    cout<<temp->data<<'\n';
    temp=temp->next;

   }
    return 0;
}