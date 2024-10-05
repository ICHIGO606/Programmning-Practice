#include<iostream>
#include<vector>
#include<string>
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
    q.push(root);
    int i=1;
    while(i<arr.size()){
        Node* temp=q.front();
        q.pop();
        if(arr[i]!=0){
            temp->left=new Node(arr[i]);
            q.push(temp->left);
        }
        i++;
        if(i<arr.size()&& arr[i]!=0){
            temp->right=new Node(arr[i]);
            q.push(temp->right);
        }
        i++;
        
    }
    return root;
}
void preOrder(Node* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
int main(){
    cout<<"enter the size of the array"<<endl;
    int size;
    cin>>size;
    vector<int> arr(size);
    cout<<"enter the element of the array"<<endl;
    for(int i=0;i<size;i++){
        string element;
        cin>>element;
        if(element=="null"){
            arr[i]=0;
        }
        else{
            arr[i]=stoi(element);
        }
    }
    Node* root=arrToTree(arr);
    preOrder(root);

}