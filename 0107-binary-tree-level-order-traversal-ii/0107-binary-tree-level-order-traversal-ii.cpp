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
    int depth(TreeNode* root){
        if(root == NULL){return 0;}
        return max(depth(root->left),depth(root->right))+1;
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int d = depth(root);
        vector<vector<int>> ans(d);
        if(root == NULL){return ans;}
        queue<TreeNode* >q;
        q.push(root);
        while(!q.empty()){
            int count = q.size() ;
            vector<int> subans;
            for(int i = 0 ; i<count ; i++){
                TreeNode *curr = q.front();
                q.pop();
                subans.push_back(curr->val);
                if(curr->left){q.push(curr->left);}
                if(curr->right){q.push(curr->right);}
            }
            ans[d-1]=subans;
            d--;
        }
        // reverse(ans.begin(),ans.end());
        return ans;
        
    }
};