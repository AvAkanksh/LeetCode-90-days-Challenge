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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){return ans;}
        queue<TreeNode *> s;
        s.push(root);
        while(!s.empty()){
            vector<int> subans;
            int count = s.size();
            for(int i = 0 ; i < count ; i++){
                TreeNode *curr = s.front();
                s.pop();
                subans.push_back(curr->val);
                if(curr->left!=NULL){s.push(curr->left);}
                if(curr->right!=NULL){s.push(curr->right);}
            }
            ans.push_back(subans);
        }
        return ans;
    }
};