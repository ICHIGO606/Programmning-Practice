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
Node* inorderToBST(vector<int>&in,int s,int e){
    if(s>e){
        return NULL;
    }
    int m=s+(e-s)/2;
    int element=in[m];
    Node* root=new Node(element);
    root->left=inorderToBST(in,s,m-1);
    root->right=inorderToBST(in,m+1,e);
    return root;
}
Node* inorderToBST(vector<int>&in){
    int s=0;
    int e=in.size()-1;
    Node* root=inorderToBST(in,s,e);
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
        }else{
            cout<<temp->data<<" ";
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }
}
void storeInorder(Node* root,vector<int>&in){
    if(root==NULL){
        return;
    }
    storeInorder(root->left,in);
    in.push_back(root->data);
    storeInorder(root->right,in);
}
bool findTarget(Node* root,int target){
    vector<int>in;
    storeInorder(root,in);
    int s=0;
    int e=in.size()-1;
    while(s<e){
        int sum=in[s]+in[e];
        if(sum==target){
            return true;
        }
        if(sum>target){
            e--;
        }
        else{
            s++;
        }
    }return false;
}
void inorder(Node* root){
    if(root==NULL)return;
    inorder(root->left);
    if(root->left==NULL && root->right==NULL){
        cout<<root->data<<" ";
    }
    inorder(root->right);
}
void printgivenlevel(Node* root,int level){
    if(root==NULL){
        return;
    }
    if(level==0){
        cout<<root->data<<" ";
    }
    else if(level>0){
        printgivenlevel(root->left,level-1);
        printgivenlevel(root->right,level-1);
    }
}
int main(){
    vector<int>in={1,2,3,4,5,6,7,8,9,10};
    Node* root=inorderToBST(in);
    levelorder(root);
    bool ans=findTarget(root,16);
    cout<<ans<<endl;
    inorder(root);
    cout<<endl;
    printgivenlevel(root,2);

}