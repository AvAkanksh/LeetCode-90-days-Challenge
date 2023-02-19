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
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){return ans;}
        bool order=true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int count = q.size();
            vector<int> subans;
            for(int i = 0 ; i<count ; i++){
                TreeNode* curr = q.front();
                q.pop();
                subans.push_back(curr->val);
                if(curr->left){q.push(curr->left);}
                if(curr->right){q.push(curr->right);}
            }
            if(order){
                cout<<"straight"<<endl;
                ans.push_back(subans);
            }
            else{
                cout<<"reversed"<<endl;
                reverse(subans.begin(),subans.end());
                ans.push_back(subans);
            }
            order = !order;
        }
        return ans;        
    }
};