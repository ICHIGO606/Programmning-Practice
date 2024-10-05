//print the nodes at the given level order in the binary search tree
#include<iostream>
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
Node* arrayToBST(vector<int>&nums,int s,int e){
    if(s>e){
        return NULL;
    }
    int m=s+(e-s)/2;
    int element=nums[m];
    Node* root=new Node(element);
    root->left=arrayToBST(nums,s,m-1);
    root->right=arrayToBST(nums,m+1,e);
    return root;

}
void printgivenlevel(Node* root,int level){
    if(root==NULL){
        return;
    }
    if(level==1){
        cout<<root->data<<" ";
    }
    else if(level>1){
        printgivenlevel(root->left,level-1);
        printgivenlevel(root->right,level-1);
    }
}
void printlevelorder(Node* root,int level){
    for(int i=1;i<=level;i++){
        cout<<"level "<<i<<":";
        printgivenlevel(root,i);
        cout<<endl;
    }
}

int main(){
    vector<int>arr={3,5,7,10,12,15,18};
    Node* root=arrayToBST(arr,0,arr.size()-1);
    cout<<endl;
    printgivenlevel(root,2);
    cout<<endl;
    printlevelorder(root,3);

}
