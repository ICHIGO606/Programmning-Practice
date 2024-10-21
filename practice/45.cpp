/*Top view of binary treeGiven a binary tree, print the nodes in left to right manner as visible from above the tree*/
#include<iostream>
#include<queue>
#include<map>
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
void topView(Node* root){
    if(!root)return;    
    map<int,int>m;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto temp=q.front();
        Node* frontNode=temp.first;
        int hd=temp.second;
        q.pop();
        if(m.find(hd)==m.end()){
            m[hd]=frontNode->data;
        }
        if(frontNode->left)q.push({frontNode->left,hd-1});
        if(frontNode->right)q.push({frontNode->right,hd+1});
    }
    for(auto i:m){
        cout<<i.second<<" ";
    }
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    topView(root);
}