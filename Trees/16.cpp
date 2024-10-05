//right view of a binary tree
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
vector<int> rightView(Node* root){
    vector<int>rightViewElements;
    if(root==NULL){
        return rightViewElements;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();
            if(i==0){
                rightViewElements.push_back(temp->data);
            }
            if(temp->right) q.push(temp->right);
            if(temp->left) q.push(temp->left);
        }
    }return rightViewElements;
}

int main(){
    Node* root=NULL;
    buildFromLevelTraversal(root);
    vector<int>rightElements=rightView(root);
    for(int right:rightElements){
        cout<<right<<" ";
    }
    cout<<endl;
}