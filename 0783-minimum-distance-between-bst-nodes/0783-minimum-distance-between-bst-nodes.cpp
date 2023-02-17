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
    void inorderTraversal(TreeNode* root , vector<int> &myList){
        if(root==NULL){
            return; 
        }
        inorderTraversal(root->left,myList);
        myList.push_back(root->val);
        inorderTraversal(root->right,myList);
    }
    
    int minDiffInBST(TreeNode* root) {
        vector<int> myList;
        inorderTraversal(root,myList);
        int ans = INT_MAX;
        for(int i  = 1; i<myList.size() ; i++){
            ans = min(myList[i]-myList[i-1], ans);
        }
        return ans;
    }
};