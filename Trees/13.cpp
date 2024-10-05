//lca 
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
Node* lowestCommonAncestor(Node* root,int p,int q){
    
    if(root==NULL){
        return NULL;
    }
    if((root->data==p )||(root->data==q)){
        return root;
    }
    Node* leftAns=lowestCommonAncestor(root->left,p,q);
    Node* rightAns=lowestCommonAncestor(root->right,p,q);
    if(leftAns==NULL && rightAns==NULL){
        return NULL;
    }
    else if(leftAns!=NULL && rightAns==NULL){
        return leftAns;
    }
    else if(leftAns==NULL && rightAns!=NULL){
        return rightAns;
    }
    else{
        return root;
    }
}
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
int main(){
    Node* root=NULL;
    buildFromLevelTraversal(root);
    cout<<"enter p"<<endl;
    int p;
    cin>>p;
    cout<<"enter q"<<endl;
    int q;
    cin>>q;
    Node* lca=lowestCommonAncestor(root,p,q);
    cout<<lca->data;
}
