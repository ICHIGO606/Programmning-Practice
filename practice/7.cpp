#include<iostream>
#include<vector>
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
Node* arrToTree(vector<int>&arr){
    if(arr.empty()){
        return NULL;
    }
    Node* root=new Node(arr[0]);
    queue<Node*>q;
    int i=1;
    q.push(root);
    while(i<arr.size()){
        Node* temp=q.front();
        q.pop();
        if(arr[i]!=-1){
            temp->left=new Node(arr[i]);
            q.push(temp->left);
        }
        i++;
        if(i<arr.size()&& arr[i]!=-1){
            temp->right=new Node(arr[i]);
            q.push(temp->right);
        }
        i++;
    }
    return root;
}
void levelorder(Node* root){
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
vector<int> leftView(Node* root){
    vector<int>leftViewElements;
    if(root==NULL){
        return leftViewElements;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();
            if(i==0){
                cout<<temp->data<<" ";
            }
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }return leftViewElements;
}
vector<int> rightView(Node* root){
    vector<int>rightElements;
    if(root==NULL){
        return rightElements;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();
            if(i==0){
                cout<<temp->data<<" ";
            }
            if(temp->right)q.push(temp->right);
            if(temp->left)q.push(temp->left);
        }
    }return rightElements;
}
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    vector<int>arr={1,2,3,4,5,6,7,8,9};
    Node* root=arrToTree(arr);
    levelorder(root);
    preorder(root);
    cout<<endl<<"left view of elements"<<endl;
    leftView(root);
    cout<<endl<<"right view of elements"<<endl;
    rightView(root);
}