#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* lca(Node* root,Node* p,Node* q){
    if(root==NULL){
        return NULL;
    }
    if(root->data==p->data||root->data==q->data){
        return root;
    }
    Node* leftAns=lca(root->left,p,q);
    Node* rightAns=lca(root->right,p,q);
    if(leftAns==NULL &&rightAns==NULL){
        return NULL;
    }
    else if(leftAns!=NULL&&rightAns==NULL){
        return leftAns;
    }
    else if(leftAns==NULL && rightAns!=NULL){
        return rightAns;
    }
    else{
        return root;
    }
}
