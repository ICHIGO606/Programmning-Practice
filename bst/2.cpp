//find node in bst
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
Node* buildBST(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if (root->data>data){
        root->left=buildBST(root->left,data);
    }
    else{
        root->right=buildBST(root->right,data);
    }
    return root;
}
Node* input(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=buildBST(root,data);
        cin>>data;
    }
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
bool findNodeinBST(Node* root,int target){
    if(root==NULL){
        return false;
    }
    if(root->data=target){
        return true;
    }
    bool leftAns=false;
    bool rightAns=false;
    if(root->data>target){
        leftAns=findNodeinBST(root->left,target);
    }else{
        rightAns=findNodeinBST(root->right,target);
    }
    return leftAns||rightAns;
}
int main(){
    Node* root=NULL;
    
    input(root);
    printLevelOrder(root);
    bool ans=findNodeinBST(root,48);
    cout<<"prsent or not "<<ans<<endl;
}