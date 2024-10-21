/*Largest BST in a binary treeGiven a Binary Tree, write a program that returns the size of the largest subtree which is also aBinary Search Tree (BST)*/
#include<iostream>
#include<algorithm>
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
class info{
    public:
    bool isBST;
    int size;
    int min;
    int max;
    info(bool bst,int s,int mi,int ma):isBST(bst),size(s),min(mi),max(ma){}
};
class Solution{
    private:
    int maxSize;
    info largestBSTHelper(Node* root){
        if(!root){
            return info(true,0,INT_MAX,INT_MIN);
        }
        info leftInfo=largestBSTHelper(root->left);
        info rightInfo=largestBSTHelper(root->right);
        if(leftInfo.isBST&&rightInfo.isBST&&root->data>leftInfo.max&& root->data<rightInfo.min){
            int size=leftInfo.size+rightInfo.size+1;
            maxSize=max(maxSize,size);
            int minVal=min(root->data,leftInfo.min);
            int maxVal=max(root->data,rightInfo.max);
            return info(true,size,minVal,maxVal);
        }
        return info(false,0,0,0);
    }
    public:
    Solution():maxSize(0){}
    int largestSize(Node* root){
        maxSize=0;
        largestBSTHelper(root);
        return maxSize;
    }
};
int main(){
    Solution sol;
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7);
    cout<<sol.largestSize(root);
}