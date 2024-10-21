//top view of binary tree
#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
void topView(Node* root){
    if(!root)return ;
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