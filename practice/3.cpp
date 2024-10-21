#include<iostream>
#include<queue>
#include<cmath>
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
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}
int diameter(Node* &root,int &ans){
    if(root==NULL){
        return 0;
    }
    int left=diameter(root->left,ans);
    int right=diameter(root->right,ans);
    ans=max(ans,left+right+1);
    return max(left,right)+1;
}
int getDiameter(Node* root){
    int ans=0;
    diameter(root,ans);
    return ans;
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
bool checkBalanced(Node* root){
    if(root==NULL){
        return true;
    }
    int leftHeight=height(root->left);
    int rightHeight=height(root->right);
    int diff=abs(leftHeight-rightHeight);

    bool ans=(diff<=1);
    bool leftCheck=checkBalanced(root->left);
    bool rightCheck=checkBalanced(root->right);
    if(ans && leftCheck &&rightCheck){
        return true;
    }
    else{
        return false;
    }
}
int convertIntoSumTree(Node* root){
    if(root==NULL){
        return 0;
    }
    int left=convertIntoSumTree(root->left);
    int right=convertIntoSumTree(root->right);
    int oldVal=root->data;
    root->data=left+right;
    return root->data+oldVal;
}
void levelOrder(Node* root){
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
        }else{
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
    Node* root=buildTree(root);
    levelOrder(root);
    cout<<height(root)<<endl;
    
    cout<<getDiameter(root)<<endl;
    bool ans=checkBalanced(root);
    if(ans){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    convertIntoSumTree(root);
    levelOrder(root);

}