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
void     printLevelOrder(Node* root){
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
int main(){
    //5 1 3 -1 -1 8 1 9 -1 -1 -1 -1 -1
    Node* root=NULL;
    root=buildTree(root);
    printLevelOrder(root);
}