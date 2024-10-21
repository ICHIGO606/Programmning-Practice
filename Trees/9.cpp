//convert binary tree into sum tree
void convertIntoSumTree(Node* root){
    if(root==NULL){
        return 0;
    }
    int left=convertIntoSumTree(root->left);
    int right=convertIntoSumTree(root->right);
    root->data=left+right+root->data;
}