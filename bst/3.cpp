//delete a node in bst

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
Node* findNodeinBST(Node* root,int target){
    if(root==NULL){
        return NULL;
    }
    if(root->data==target){
        return root;
    }
   
    if(root->data>target){
        return findNodeinBST(root->left,target);
    }else{
        return findNodeinBST(root->right,target);
    }
    
}
int maxVal(Node* root){
    Node* temp=root;
    if(temp==NULL){
        return -1;
    }
    while(temp!=NULL){
        temp=temp->right;
    }
    return temp->data;
}
Node* deleteNode(Node* root,int target){
    if(root==NULL){
        return NULL;
    }
    if(root->data==target){
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        else if(root->left==NULL && root->right!=NULL){
            Node* child=root->right;
            delete root;
            return child;
        }
        else if(root->right==NULL && root->left!=NULL){
            Node* child=root->left;
            delete root;
            return child;
        }
        else{
            int inorderpre=maxVal(root->left);
            root->data=inorderpre;
            root->left=deleteNode(root,inorderpre);
            return root;
        }
    }
    else if(target<root->data){
        root->left=deleteNode(root->left,target);
    }
    else if(target>root->data){
        root->right=deleteNode(root->right,target);
    }
    return root;
}
int main(){
    Node* root=NULL;
    
    input(root);
    printLevelOrder(root);
    deleteNode(root,6);
    printLevelOrder(root);
   
}