class Solution {
    bool isSumSame(TreeNode *p, int sum, int target) {
        if (!p) return false;

        sum += p->val;

        // Check ONLY when standing on a leaf node
        if (!p->left && !p->right) {
            return sum == target;
        }

        // Check if EITHER branch finds a valid leaf path
        return isSumSame(p->left, sum, target) || isSumSame(p->right, sum, target);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        return isSumSame(root, 0, targetSum);
    }
};