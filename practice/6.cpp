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
void solve(Node* root,int targetSum,int &currSum,vector<int>&path,vector<vector<int>>&ans){
    if(root==NULL){
        return;
    }
    if(root->left==NULL  && root->right==NULL){
        path.push_back(root->data);
        currSum+=root->val;
        if(currSum==targetSum){
            ans.push_back(path);
        }
        path.pop_back();
        currSum-=root->data;
        return;
    }
    path.push_back(root->data);
    currSum+=root->data;
    solve(root->left,targetSum,currSum,path,ans);
    solve(root->right,targetSum,currSum,path,ans);
    path.pop_back();
    currSum-=root->data;

}
vector<vector<int>> findPath(Node* root,int targetSum){
    vector<vector<int>>ans;
    vector<int>temp;
    int sum=0;
    solve(root,targetSum,sum,temp,ans);
    return ans;
}