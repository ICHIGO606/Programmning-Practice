/*You are given two non-empty linked lists representing two non-negative integers. The
digits are stored in reverse order, and each of their nodes contains a single digit. Add
the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number
0 itself.
Input:
First line contains length of both linked list n1 and n2.
Second line contains the all n1 elements present in linked list 1
Third line contains the all n2 elements present in linked list 1
Output:
All elements of final linked which contains sum*/
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
Node* addTwoLists(Node* l1,Node* l2){
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
    }
    return dummy->next;
}
void printList(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node* createList(vector<int>&values){
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
int main(){
    int n1,n2;
    cin>>n1>>n2;
    vector<int>values1(n1),values2(n2);
    for(int i=0;i<n1;i++){
        cin>>values1[i];
    }
    for(int i=0;i<n2;i++){
        cin>>values2[i];
    }
    Node* l1=createList(values1);
    Node* l2=createList(values2);
    Node* result=addTwoLists(l1,l2);
    printList(result);
}