//left view of a binary tree
#include<iostream>
#include<queue>
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
vector<int> leftView(Node* root){
    vector<int> leftViewElements;
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
                leftViewElements.push_back(temp->data);
            }
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }
    return leftViewElements;
}
int main(){
    Node* root=NULL;
    buildFromLevelTraversal(root);
    vector<int>leftViewNode=leftView(root);
    for(int nodesleft:leftViewNode){
        cout<<nodesleft<<" ";
    }
    cout<<endl;
}