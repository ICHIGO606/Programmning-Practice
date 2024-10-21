#include<iostream>
#include<queue>
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
vector<int> zigZagTraversal(Node* root){
    vector<int>result;
    if(root==NULL){
        return NULL;
    }
    queue<Node*>q;
    int count=0;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        count++;
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            result.push_back(root->data);
            if(count%2==0){
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }else{
                if(temp->right)q.push(temp->right);
                if(temp->left)q.push(temp->right);
            }
            q.pop();
        }
    }return result;
}