//check if the tree is balanced or not
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
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftHeight=height(root->left);
    int rightHeight=height(root->right);
    int maxHeight=1+max(leftHeight,rightHeight);
    return maxHeight;
}
bool checkBalanced(Node* root){
    if(root==NULL){
        return true;
    }
    int leftHeight=height(root->left);
    int rightHeight=height(root->right);
    int diff=abs(leftHeight-rightHeight);

    bool ans1=(diff<=1);

    bool leftCheck=checkBalanced(root->left);
    bool rightCheck=checkBalanced(root->right);
    if(ans1 && leftCheck && rightCheck){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    Node* root=NULL;
    buildFromLevelTraversal(root);
    bool ans=checkBalanced(root);
    cout<<"the tree is balanced or not "<<ans<<endl;
}