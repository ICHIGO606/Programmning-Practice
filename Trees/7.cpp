//diameter of a tree
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
void buildFromLevelTraversal(Node* &root){
    int data;
    cout<<"enter root: "<<endl;
    cin>>data;
    root=new Node(data);
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        cout<<"enter the left of "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData!=-1){
            temp->left=new Node(leftData);
            q.push(temp->left);
        }
        cout<<"enter the right of "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData!=-1){
            temp->right=new Node(rightData);
            q.push(temp->right);
        }
    }
}
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
int diameter(Node* &root,int &ans){
    if(root==NULL){
        return 0;
    }
    int left=diameter(root->left,ans);
    int right=diameter(root->right,ans);
    ans=max(ans,1+left+right);
    return 1+max(left,right);
}
int main(){
    Node* root=NULL;
    int ans=0;
    root=buildTree(root);
    diameter(root,ans);
    cout<<"diameter of the tree is "<<ans;
}