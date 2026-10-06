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
    int findifbal(TreeNode* root){
        if(!root) return 0;

        int left = findifbal(root->left);
        if(left == -1) return -1;

        int right = findifbal(root->right);
        if(right == -1) return -1;


        if(abs(left - right) <= 1){
            int value = 1+max(left,right);
            return value;
        }
        return -1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(findifbal(root)>0) return true;
        return false;
    }
};