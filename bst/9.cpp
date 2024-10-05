//array to bst to print leaf nodes
#include <iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* insert(Node* root,int val){
    if(root==NULL){
        return new Node(val);
    }
    if(root->val>val){
        insert(root->left,val);
    }
    else{
        insert(root->right,val);
    }
    return root;
}
Node* arrayToBST(vector<int>&nums,int s,int e){
    if(s>e){
        return NULL;
    }
    int m=s+(e-s)/2;
    Node* root=new Node(nums[m]);
    root->left=arrayToBST(nums,s,m-1);
    root->right=arrayToBST(nums,m+1,e);
    return root;
}
void levelorder(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->val<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    if(root->left==NULL && root->right==NULL){
        cout<<root->val<<" ";
    }
    inorder(root->right);
}

int main() {
    vector<int>nums={5, 3, 8, 2, 4, 7, 9};
    Node* root=arrayToBST(nums,0,nums.size()-1);
    levelorder(root);
    cout<<"inorder traversal of the tree:"<<endl;
    inorder(root);
    return 0;
}