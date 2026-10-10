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
        if(!root) return NULL;
        if(root->val == p->val || root->val == q->val){
            return root;
        }
        TreeNode *left_val = lowestCommonAncestor(root->left,p,q);
        TreeNode *right_val = lowestCommonAncestor(root->right,p,q);

        if(left_val && right_val) return root;
        else if(left_val!=NULL) return left_val;
        else return right_val;
    }
};