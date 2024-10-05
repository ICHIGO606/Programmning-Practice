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
Node* buildTree(Node* root){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    root=new Node(data);
    root->left=buildTree(root->left);
    root->right=buildTree(root->right);
    return root;
}
void inOrder(Node* root, vector<int>&lf){
    if(root==NULL){
        return;
    }
    inOrder(root->left,lf);
    if(root->left==NULL && root->right==NULL){
        lf.push_back(root->data);
    }
    inOrder(root->right,lf);
}
int main(){
    
    Node* root=buildTree(root);
    vector<int>lf;
    inOrder(root,lf);
    for(int i=0;i<lf.size();i++){
        cout<<lf[i]<<" ";
    }
    cout<<endl;
}