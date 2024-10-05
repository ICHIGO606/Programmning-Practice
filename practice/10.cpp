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
    if(root->data>data){
        root->left=buildBST(root->left,data);
    }
    else{
        root->right=buildBST(root->right,data);
    }
    return root;
}
Node* insert(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=buildBST(root,data);
        cin>>data;
    }
    return root;
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
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }
}
bool findNodeinBST(Node* root,int target){
    if(root==NULL){
        return false;
    }
    if(root->data==target){
        return true;
    }
    int leftAns=false;
    int rightAns=false;
    if(root->data>target){
        leftAns=findNodeinBST(root->left,target);
    }else{
        rightAns=findNodeinBST(root->right,target);
    }
    return leftAns||rightAns;
}
int maxVal(Node* root){
    Node* temp=root;
    if(temp==NULL){
        return -1;
    }
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp->data;
}
Node* deleteNode(Node* root,int target){
    if(root==NULL){
        return NULL;
    }
    if(root->data==target){
        if(root->left==NULL&& root->right==NULL){
            delete root;
            return NULL;
        }
        else if(root->left==NULL && root->right!=NULL){
            Node* child=root->right;
            delete root;
            return child;
        }
        else if(root->left!=NULL && root->right==NULL){
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
    else if(root->data>target){
        root->left=deleteNode(root->left,target);
    }
    else{
        root->right=deleteNode(root->right,target);
    }
    return root;
}
bool solve(Node* root,long long int lb,long long int ub){
    if(root==NULL){
        return true;
    }
    if((root->data>lb && root->data<ub)&& solve(root->left,lb,root->data)&&solve(root->right,root->data,ub)){
        return true;
    }else{
        return false;
    }
}
bool isValidBST(Node* root){
    long long int lb=-4354646546811;
    long long int ub=4354646546811;
    bool ans= solve(root,lb,ub);
    return ans;
}
Node* findNode(Node* root,int val){
    if(root==NULL){
        return NULL;
    }
    if(root->data==val){
        return root;
    }
    else if(root->data>val){
        findNode(root->left,val);
    }
    else{
        findNode(root->right,val);
    }
}
Node* lca(Node* root,Node* p,Node* q){
    if(root==NULL||root->data==p->data||root->data==q->data){
        return root;
    }
    if(root->data>p->data&& q->data>root->data){
        return root;
    }
    else if(root->data>p->data && root->data>q->data){
        return lca(root->left,p,q);
    }
    else if(root->data<p->data && root->data<q->data){
        return lca(root->right,p,q);
    }
    else{
        return root;
    }
}
int kthSmallest(Node* root,int &k){
    if(root==NULL){
        return -1;
    }
    int leftAns=kthSmallest(root->left,k);
    if(leftAns!=-1){
        return leftAns;
    }
    k--;
    if(k==0){
        return root->data;
    }
    int rightAns=kthSmallest(root->right,k);
    return rightAns;
}
int main(){
    Node* root=NULL;
    insert(root);
    levelOrder(root);
    int target=123;
    if(isValidBST(root)){
        cout<<"yes"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    deleteNode(root,123);
    levelOrder(root);
    if(findNodeinBST(root,target)){
        cout<<"yes"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    int pval=20,qval=46;
    Node* p=findNode(root,pval);
    Node* q=findNode(root,qval);
    Node* lowestCommonAncestor=lca(root,p,q);
    cout<<lowestCommonAncestor->data<<endl;
    int k=3;
    cout<<kthSmallest(root,k)<<endl;

}