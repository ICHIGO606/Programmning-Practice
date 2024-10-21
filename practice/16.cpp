/*Given three linked lists, say a, b and c, find one node from each list such that the sum of the values
of the nodes is equal to a given number say, Target. As any number of answers can be possible
return the first one you get while traversing.
Input Format
The First Line contains 3 Integers n, m and k as the Size of the Three LinedLists. Next 3 Lines
contains n, m and k integers Respectively as the elements of Linked Lists. Next Line contains the an
Integer as Target.
*/
#include<iostream>
#include<unordered_set>
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
Node* createList(vector<int>&nums){
    Node* head=NULL;
    Node* tail=NULL;
    for(int num:nums){
        if(head==NULL){
            head=new Node(num);
            tail=head;
        }else{
            tail->next=new Node(num);
            tail=tail->next;
        }
    }return head;
}
void findTriplets(Node* a, Node* b,Node* c,int target){
    Node* acurr=a;
    while(acurr!=NULL){
        Node* bcurr=b;
        while(bcurr!=NULL){
            Node*ccurr=c;
            while(ccurr!=NULL){
                if(acurr->data+bcurr->data+ccurr->data==target){
                    cout<<acurr->data<<" "<<bcurr->data<<" "<<ccurr->data<<endl;
                    return;
                }
                ccurr=ccurr->next;
            }
            bcurr=bcurr->next;
        }
        acurr=acurr->next;
    }
    cout<<"No triplets found"<<endl;
}
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>nums_a(n),nums_b(m),nums_c(k);
    for(int i=0;i<n;i++){
        cin>>nums_a[i];
    }
    for(int i=0;i<m;i++){
        cin>>nums_b[i];
    }
    for(int i=0;i<k;i++){
        cin>>nums_c[i];
    }
    Node* l1=createList(nums_a);
    Node* l2=createList(nums_b);
    Node* l3=createList(nums_c);
    int target;
    cin>>target;
    findTriplets(l1,l2,l3,target);
}