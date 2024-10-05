//largest bst in a binary tree
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
    info largestBSThelper(Node* root){
        if(!root)return info(true,0,INT_MAX,INT_MIN);
        info leftinfo=largestBSThelper(root->left);
        info rightinfo=largestBSThelper(root->right);
        if(leftinfo.isBST&&rightinfo.isBST&&root->data>leftinfo.max&&root->data<rightinfo.max){
            int size=leftinfo.size+rightinfo.size+1;
            maxSize=max(maxSize,size);
            int minVal=min(root->data,leftinfo.min);
            int maxval=max(root->data,rightinfo.max);
            return info(true,size,minVal,maxVal);
        }
        return info(false,0,0,0);
    }
    public:
    solution():maxSize(0){}
    int largestSize(Node* root){
        maxSize=0;
        largestBSThelper(root);
        return maxSize;
    }
}
