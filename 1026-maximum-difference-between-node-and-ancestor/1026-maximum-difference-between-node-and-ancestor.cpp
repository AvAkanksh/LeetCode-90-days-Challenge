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
    int helper(TreeNode* root, int curmin , int curmax){
        if(root==NULL){
            return curmax-curmin;
        }
        curmin = min(curmin,root->val);
        curmax = max(curmax,root->val);
        
        int left = helper(root->left, curmin,curmax);
        int right = helper(root->right, curmin,curmax);
        return max(left,right);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        return helper(root,root->val,root->val);
    }
};