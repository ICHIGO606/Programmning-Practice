/*Q11. Sum Root to Leaf Numbers
You are given the root of a binary tree containing digits from 0 to 9 only.
Each root-to-leaf path in the tree represents a number.
For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
A leaf node is a node with no children.
Input:
First line contains value all Nodes of Tree
Note: all -1 input denotes NULL node
Output:
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the
answer will fit in a 32-bit integer.*/
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

int sumNumbers(Node* root,int currSum){
    currSum=currSum*10+root->data;
    if(root->left==NULL &&root->right==NULL){
        return currSum;
    }
    int leftSum=sumNumbers(root->left,currSum);
    int rightSum=sumNumbers(root->right,currSum);
    return leftSum+rightSum;
}
int sumNumbers(Node* root){
    return sumNumbers(root,0);
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    cout<<sumNumbers(root);
}