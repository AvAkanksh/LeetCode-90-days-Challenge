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
    void helper(TreeNode* root , vector<int> &ans){
        if(root== NULL){
            return;
        }
        helper(root->left , ans);
        ans.push_back(root->val);
        helper(root->right , ans);
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return true;
        }
        helper(root, ans);
        for(int i = 1 ; i< ans.size() ; i++){
            if(ans[i-1]>=ans[i]){
                return false;
            }
        }
        return true;
    }
};