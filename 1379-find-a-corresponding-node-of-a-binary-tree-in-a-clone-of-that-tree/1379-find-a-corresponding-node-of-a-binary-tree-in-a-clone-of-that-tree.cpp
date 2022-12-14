/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original==target){
            return cloned;
        }
        TreeNode* ans = NULL;
        if(original->right!=NULL){
            ans = getTargetCopy(original->right,cloned->right,target);
        }
        if(original->left!=NULL && !(ans)){
            ans = getTargetCopy(original->left,cloned->left,target);
        }
        return ans;
    }
};