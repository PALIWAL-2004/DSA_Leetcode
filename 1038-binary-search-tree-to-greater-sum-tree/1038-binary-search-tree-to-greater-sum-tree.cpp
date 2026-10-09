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
int sum = 0;
    void ctv(TreeNode *root){
   if(!root) return ;
    ctv(root->right);
    sum = sum + root->val;
    root->val = sum;
    ctv(root->left);
    
}
public:
    TreeNode* bstToGst(TreeNode* root) {
        ctv(root);
        return root;


    }
};