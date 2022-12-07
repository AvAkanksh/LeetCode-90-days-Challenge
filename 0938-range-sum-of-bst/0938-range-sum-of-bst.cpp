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
    void inorder_traversal(TreeNode* root, int low , int high , int &sum){
        if(root == NULL){
            return;
        }
        int val =  root->val;
        if(val>low){
            inorder_traversal(root->left,low,high,sum);
        }
        if(val>=low && val<=high){
            sum+=val;
        }
        if(val<high){
            inorder_traversal(root->right,low,high,sum);
        }
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        inorder_traversal(root,low,high,sum);
        return sum;
    }
};