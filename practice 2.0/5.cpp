#include<iostream>
#include<vector>
using namespace std;
void findTriplets(Node* l1,Node* l2,Node* l3,int target){
    Node* acurr=a;
    while(acurr!=NULL){
        Node* bcurr=b;
        while(bcurr!=NULL){
            Node* ccurr=c;
            while(ccurr!=NULL){
                if(acurr->data+bcurr->data+ccurr->data==target){
                    cout<<acurr->data<<" "<<bcurr->data<<" "<<ccurr->data<<endl;
                    return;
                }
            }
        }
    }cout<<"triplet not found"<<endl;
}