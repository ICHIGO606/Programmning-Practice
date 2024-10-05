#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<string>
#include<stack>
using namespace std;
class Node{
    public:
    int data;
    Node* left;Node* right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* buildTree(Node* root){
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    root->left=buildTree(root->left);
    root->right=buildTree(root->right);
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
void buildLevelOrder(Node* &root){
    int data;
    cin>>data;
    if(data!=-1){
        root=new Node(data);
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        int leftData;
        cin>>leftData;
        if(leftData!=-1){
            temp->left=new Node(leftData);
            q.push(temp->left);
        }
        int rightData;
        cin>>rightData;
        if(rightData!=-1){
            temp->right=new Node(rightData);
            q.push(temp->right);
        }
    }
}
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void printLeaf(Node* root,vector<int>&lf){
    if(root==NULL)return;
    printLeaf(root->left);
    if(root->left==NULL&&root->right==NULL){
        lf.push_back(root->data);
    }
    printLeaf(root->right);
}
int height(Node* root){
    if(root==NULL)return 0;
    return 1+max(height(root->left),height(root-.right));
}
int diameter(Node* &root,int &ans){
    if(root==NULL)return 0;
    int left=diameter(root->left,ans);
    int right=diameter(root->right,ans);
    ans=max(ans,left+right);
    return 1+max(left,right);
}
int getDiameter(Node* root){
    int ans=0;
    diameter(root,ans);
    return ans;
}
bool checkBalanced(Node* root){
    if(root==NULL)return true;
    int leftHeight=height(root->left);
    int rightHeight=height(root->right);
    int diff=abs(leftHeight-rightHeight);

    bool ans=diff<=1;
    bool leftAns=checkBalanced(root->left);
    bool rightAns=checkBalanced(root->right);
    if(ans&&leftAns&&rightAns){
        return true;
    }else{
        return false;
    }
}
int convertIntoSumTree(Node*root){
    if(root==NULL)return 0;
    int leftData=convertIntoSumTree(root->left);
    int rightData=convertIntoSumTree(root->right);
    int oldData=root->data;
    root->data=leftData+rightData;
    return root->data+oldData;
}
Node* lca(Node* root,Node* p,Node* q){
    if(root==NULL)return NULL;
    if(root->data==p->data||root->data==q->data)return root;
    Node* leftAns=lca(root->left,p,q);
    Node* rightAns=lca(root->right,p,q);
    if(leftAns==NULL&&rightAns==NULL)return NULL;
    else if(leftAns!=NULL&&rightAns==NULL)return leftAns;
    else if(leftAns==NULL&&rightAns!=NULL)return rightAns;
    else{
        return root;
    }
}
bool symmetric(Node* rleft,Node* rright){
    if(rleft==NULL||rright==NULL){
        return rleft==rright;
    }
    if(rleft->data!=rright->data){
        return false;
    }
    return symmetric(rleft->left,rright->right)&&symmetric(rleft->right,rright->left);
}
bool checkSymmetric(Node* root){
    if(root==NULL)return true;
    return symmetric(root->left,root->right);
}
void solve(Node* root,int target,int &currSum,vector<int>&path,vector<vector<int>>&ans){
    if(root==NULL)return;
    if(root->left==NULL&&root->right==NULL){
        path.push_back(root->data);
        currSum+=root->data;
        if(currSum==target){
            ans.push_back(path);
        }
        path.pop_back();
        currSum-=root->data;
        return;
    }
    path.push_back(root->data);
    currSum+=root->data;
    solve(root->left,target,currSum,path,ans);
    solve(root->right,target,currSum,path,ans);
    path.pop_back();
    currSum-=root->data;

}
vector<vector<int>> findPath(Node* root,int target){
    int sum=0;
    vector<int>temp;
    vector<vector<int>>ans;
    solve(root,target,sum,temp,ans);
    return ans;
}
Node* buildFromArray(vector<int>&arr){
    if(arr.empty())return NULL;
    Node* root=new Node(arr[0]);
    queue<Node*>q;
    q.push(root);
    int i=1;
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(arr[i]!=-1){
            temp->left=new Node(arr[i])
            q.push(temp->left);
        }i++;
        if(arr[i]!=-1&&i<arr.size()){
            temp->right=new Node(arr[i]);
            q.push(temp->right);
        }i++;
    }return root;
}
vector<int>leftView(Node* root){
    vector<int>leftViewElements;
    if(root==NULL)return leftViewElements;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();
            if(i==0)cout<<temp->data<<" ";
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }return leftViewElements;
}
vector<int>rightView(Node* root){
    vector<int>rightViewElements;
    if(root==NULL)return rightViewElements;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();
            if(i==0)cout<<temp->data<<" ";
            if(temp->right)q.push(temp->right);
            if(temp->left)q.push(temp->left);
        }
    }return rightViewElements;
}

class Solution{
    private:
    int height;
    void placeValue(Node* root,vector<vector<string>>&ans,int row,int col){
        if(root==NULL){
            return;
        }
        ans[row][col]=to_string(root->data);
        int l=col-pow(height-row-1);
        int r=col+pow(height-row-1);
        placeValue(root->left,ans,row+1,l);
        placeValue(root->right,ans,row+1,r);
    }
    int getHeight(Node* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(getHeight(root->left),getheight(root->right));
    }
    public:
    vector<vector<string>> printTree(Node* root){
        height=findHeight(root)-1;
        int width=pow(2,height+1)-1;
        vector<vector<string>>ans(height+1,vector<string>(width,""));
        int row=0;
        int col=(width-1)/2;
        placeValue(root,ans,row,col);
        return ans;
    }
};
vector<int>zigzagTraversal(Node* root){
    vector<int>result;
    if(!root)return result;
    queue<Node*>q;
    int count=0;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        count++;
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            result.push_back(temp->data);
            if(count%2==0){
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }else{
                if(temp->right)q.push(temp->right);
                if(temp->left)q.push(temp->left);
            }q.pop();   
        }
    }return result;
}
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
bool findNodeInBST(Node* root,int target){
    if(root==NULL)return false;
    if(root->data==target){
        return true;
    }
    if(root->data>data){
        bool leftCheck=findNodeInBST(root->left,target)
    }else{
        bool rightCheck=findNodeInBST(root->right),target;
    }
    return leftCheck||rightCheck;
}
int maxVal(Node* root){
    Node* temp=root;
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
        if(root->left==NULL&&root->right==NULL){
            delete root;
            return NULL;
        }
        else if(root->left!=NULL&&root->right==NULL){
            Node*child=root->left;
            delete root;
            return child;
        }
        else if(root->left==NULL && root->right!=NULL){
            Node* child=root->right;
            delete root;
            return child;
        }
        else{
            int inorderpre=maxVal(root->left);
            root->data=inorderpre;
            root->left=deleteNode(root->left,inorderpre);
            return root;
        }
    }
    else if(target>root->data){
        deleteNode(root->right,target);
    }else{
        deleteNode(root->left,target);
    }return root;
}
bool validate(Node* root,long long int lb,long long int ub){
    if(root==NULL)return true;
    if((root->data>lb&&root->data<lb)&&(validate(root->left,lb,root->data))&&validate(root->right,root->data,ub)){
        return true;
    }else{
        return false;
    }
}
bool isValidBST(Node* root){
    long long int lb=-484564135748436;
    long long int ub=484564135748436;
    return validate(root,lb,ub);
}
Node* findNode(Node* root,int data){
    if(root==NULL)return NULL;
    if(root==data)return root;
    else if(root->data>data){
        return findNode(root->left,data);
    }else{
        return findNode(root->right,data);
    }
}
Node* BSTlca(Node* root,Node*p,Node*q){
    if(root==NULL||root->data==p->data||root->data==q->data)return root;
    if(p->data>root->data&&q->data<root->data){
        return root;
    }
    else if(root->data>p->data&&root->data>q->data){
        return BSTlca(root->left,p,q);
    }else if(root->data<p->data&&root->data<q->data){
        return BSTlca(root->right,p,q);
    }else{
        return root;
    }
}
int kthSmallest(Node* root,int &k){
    if(root==NULL)return -1;
    int leftAns=kthSmallest(root->left,k);
    if(leftAns!=-1)return leftAns;
    k--;
    if(k==0)return root->data;
    int rightAns=kthSmallest(root->right,k);
    return rightAns;
}
Node* inorderToBST(vector<int>&in,int s,int e){
    if(s>e)return NULL;
    int m=s+(e-s)/2;
    int element=in[m];
    Node* root=new Node(element);
    root->left=inorderToBST(root->left,s,m-1);
    root->right=inorderToBST(root->right,m+1,e);
    return root;
}
Node* inorderToBST(vector<int>&in){
    int s=0;int e=in.size()-1;
    Node* root=inorderToBST(in,s,e);
    return root;
}
void storeInorder(Node* root,vector<int>&in){
    if(root==NULL)return;
    storeInorder(root->left);
    in.push_back(root->data);
    storeInorder(root->right);
}
bool findTarget(Node* root,int target){
    if(root==NULL)return false;
    vector<int>in;
    storeInorder(root,in);
    int s=0;inte=in.size()-1;
    while(s<e){
        int sum=in[s]+in[e];
        if(sum==target)return true;
        if(sum>target)e--;
        else{
            s++;
        }
    }return false;
}
void printGivenLevel(Node* root,int level){
    if(root==NULL)return;
    if(level=0)cout<<root->data;
    else if(level>0){
        printGivenLevel(root->left,level-1);
        printGivenLevel(root->right,level-1);
    }
}
vector<int>nextGreaterElement(vector<int>&nums){
    int n=nums.size();
    stack<int>st;
    vector<int>result(n,-1);
    for(int i=0;i<2*n;i++){
        while(!st.empty()&&nums[st.top()]>nums[i%n]){
            result[st.top()]=nums[i%n];
            st.pop();
        }if(i<n){
            st.push(i);
        }
    }return result;
}