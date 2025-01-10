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
Node* removeFirst(Node* head){
    Node* tempo=head;
    head=head->next;
    free(tempo);
    return head;
}
Node* removeLast(Node* head){
    Node* temp5=head;
    while(temp5->next->next!=NULL){
            temp5=temp5->next; 
    }
    free(temp5->next);
    temp5->next=NULL;
    return head;
}
Node* removeAtLoc(Node* head , int position , int n){
    if (head==NULL){
        std::cout<<"List Empty";
        return head;
    }
    else if(position>n){
        std::cout<<"Not enough items in Linked List";
        return head;
    }
    else if(position==1){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    else if(position==n){
        Node* temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        Node* del=temp->next;
        temp->next=NULL;
        free(del);
        return head;
    }
    Node* current=head;
    for(int i =0 ; i<position-2; ++i){
        current=current->next;
    }
    Node* deleted=current->next;
    current->next=deleted->next;
    free (deleted);
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
    /*cout<<"After removing first : "<<'\n';
    head=removeFirst(head);
    Node* temp1=head;
    while(temp1){
        std::cout<<temp1->data<<'\n';
        temp1=temp1->next;
    }
    cout<<"After removing Last : \n";
    head=removeLast(head);
    Node* temp3=head;
    while(temp3){
        std::cout<<temp3->data<<'\n';
        temp3=temp3->next;
    }*/
   int k=5;
   std::cout<<"after deleting kth node : \n";
   head= removeAtLoc(head , k , nums.size());
   Node* temp1=head;
   while(temp1){
        std::cout<<temp1->data<<'\n';
        temp1=temp1->next;
    }

    return 0;
}
