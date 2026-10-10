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
    int ctv(TreeNode *root){
   if(!root) return 0;
    ctv(root->right);
    sum = sum + root->val;
    root->val = sum;
   
    ctv(root->left);
     return sum;
    
}
public:
    TreeNode* bstToGst(TreeNode* root) {
        ctv(root);
        return root;


    }
};