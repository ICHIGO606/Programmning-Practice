//inorder to bst
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
Node* inorderToBST(int inorder[],int s,int e){
    if(s>e){
        return NULL;
    }
    int m=(s+e)/2;
    int element=inorder[m];
    Node* root=new Node(element);
    root->left=inorderToBST(inorder,s,m-1);
    root->right=inorderToBST(inorder,m+1,e);
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
int main(){
    
    int inorder[]={1,5,7,9,11,15,17};
    int e=sizeof(inorder)/sizeof(inorder[0]);
    int s=0;
    Node* root=inorderToBST(inorder,s,e-1);
    printLevelOrder(root);

}