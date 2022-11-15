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
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL){return false;}
        unordered_set<int> s;
        queue<TreeNode*> q;
        q.push(root);
        while(!(q.empty())){
            TreeNode *curr = q.front();
            q.pop();
            int val = curr->val;
            if(s.find(k-val)!=s.end()){
                return true;
            }
            else{
                s.insert(val);
                if(curr->left){q.push(curr->left);}
                if(curr->right){q.push(curr->right);}
            }
        }
        return false;
    }
};