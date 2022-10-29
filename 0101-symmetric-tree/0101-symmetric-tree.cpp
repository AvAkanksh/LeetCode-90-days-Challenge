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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){return true;}
        return isSymmetric(root->left , root->right);
    }
    bool isSymmetric(TreeNode *leftroot, TreeNode *rightroot ){
        if(leftroot == NULL && rightroot == NULL){
            return true;
        }
        if(leftroot == NULL || rightroot == NULL){
            return false;
        }
        if(leftroot->val!=rightroot->val){return false;}
        else{
            return isSymmetric(leftroot->left , rightroot->right) && isSymmetric(leftroot->right , rightroot->left);
        }
        return false;
    }
};