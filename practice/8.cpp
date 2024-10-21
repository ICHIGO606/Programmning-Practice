#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->right=NULL;
        this->left=NULL;
    }
};
class Solution{
int height;
void placevalue(Node* root,vector<vector<string>>&ans,int row,int col){
    if(root==NULL){
        return;
    }
    ans[row][col]=to_string(root->data);
    int l=col-pow(2,height-row-1);
    int r=col+pow(2,height-row-1);
    placevalue(root->left,ans,row+1,l);
    placevalue(root->right,ans,row+1,r);
}
int getHeight(Node* root){
    if(root==NULL)return 0;
    return 1+max(getHeight(root->left),getHeight(root->right));
}
public:
    vector<vector<string>> printTree(Node* root){
    height=findHeight(root)-1;
    int widht=pow(2,height+1)-1;
    vector<vector<string>>ans(height+1,vector<string>(width,""));
    int row=0;
    int col=(width-1)/2;
    placevalue(root,ans,row,col);
    return ans;
    }
};