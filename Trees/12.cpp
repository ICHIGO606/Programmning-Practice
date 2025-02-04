//check if the binary tree is symmetric or not
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
bool symmetric(TreeNode* rleft,TreeNode* rright){
    if(rleft==NULL||rright==NULL){
        return rleft==rright;
    }
    if(rleft->val!=rright->val){
        return false;
    }
    return symmetric(rleft->left,rright->right)&& symmetric(rleft->right,rright->left);
}
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        return symmetric(root->left,root->right);
    }
};