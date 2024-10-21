//sum to leaf numbers
#include<iostream>
#include<vector>
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
int sumNumbers(Node* root,int &currSum){
    currSum=currSum*10+root->data;
    if(root->left==NULL && root->right==NULL){
        return currSum
    }
    int leftSum=sumNumbers(root,currSum);
    int rightSum=sumNumbers(root,currSum);
    return leftSum+rightSum;
}
int sumNumbers(Node* root){
    return sumNumbers(root,0);
}
