//build a tree 
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
Node* buildTree(Node* root){
    int data;
    cout<<"enter data: "<<endl;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter the data at the left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter the data at the right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}
int main(){
    Node* root=NULL;
    buildTree(root);
}