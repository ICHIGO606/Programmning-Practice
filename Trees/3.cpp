//print in the level order
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
void printLevelOrder(Node* root){
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
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
void preOrder(Node* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inorder(Node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node* root){
    if(root==NULL){
        return ; 
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* root=NULL;
    root=buildTree(root);
    printLevelOrder(root);
    inorder(root);
    cout<<endl;
    preOrder(root);
    cout<<endl;
    postorder(root);

}