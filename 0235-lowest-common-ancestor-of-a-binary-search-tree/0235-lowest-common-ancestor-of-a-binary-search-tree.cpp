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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* r = root;
        while(true){
            int rv = r->val;
            int pv = p->val;
            int qv = q->val;
            if(rv==pv){return p;}
            if(rv==qv){return q;}
            else{
                if(rv>pv && rv<qv ||rv<pv && rv>qv ){return r;}
                else{
                    if(rv>pv && rv>qv){r = r->left;}
                    else{r = r->right;}
                }
            }
        }
    }
};