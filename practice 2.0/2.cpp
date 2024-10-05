#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
Node* createList(vector<int>&values){
    int n=l.size();
    Node* head=NULL;
    Node* tail=NULL;
    for(int val:values){
        if(head==NULL){
            head=new Node(val);
            tail=head;
        }else{
            tail->next=new Node(val);
            tail=tail->next;
        }
    }return head;
}
Node* addTwoLists(Node*l1,Node* l2){
    Node* dummy=new Node(0);
    Node* current=dummy;
    int carry=0;
    while(l1!=NULL||l2!=NULL||carry!=0){
        int sum=carry;
        if(l1!=NULL){
            sum+=l1->data;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum+=l2->data;
            l2=l2->next;
        }
        carry=sum/10;
        int digit=sum%10;
        current->next=new Node(digit);
        current=current->next;
    }return dummy->next;
}
