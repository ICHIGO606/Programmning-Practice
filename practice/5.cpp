#include<isotream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->left=NULL;
        this->data=data;
        thsi->right=NULL;
    }
};
bool symmetric(Node* rleft,Node* rright){
    if(rleft==NULL||rright==NULL){
        return rleft==rright;
    }
    if (rright->val!=rleft->val){
        return false;
    }
    return symmetric(rleft->left,rright->right)&& symmetric(rleft->right,rright->left);
}
bool checkSymmetric(Node* root){
    if(root==NULL){
        return true;
    }
    return symmetric(root->left,root->right);
}