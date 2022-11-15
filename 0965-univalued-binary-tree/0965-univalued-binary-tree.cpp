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
    
    bool check(TreeNode *root, int &val){
        if(root==NULL){return true;}
        bool lcheck = check(root->left,val);
        bool rcheck = check(root->right , val);
        return (root->val == val)&&lcheck&&rcheck;
    }
    
    bool isUnivalTree(TreeNode* root) {
        if(root == NULL){return true;}
        int val = root->val;
        return check(root,val);
    }
};