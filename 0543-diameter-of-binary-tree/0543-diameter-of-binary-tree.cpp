class Solution {
    int maxDiameter = 0;

    // Helper returns the max depth (height in edges) down to a leaf
    int calculateDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0; // 0 edges from a null child to a leaf
        }

        int leftDepth = calculateDepth(root->left);
        int rightDepth = calculateDepth(root->right);

        // Longest path through THIS node is leftDepth + rightDepth
        maxDiameter = std::max(maxDiameter, leftDepth + rightDepth);

        // Return the depth of the longest branch + 1 for the edge to the parent
        return 1 + std::max(leftDepth, rightDepth);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDiameter = 0;
        calculateDepth(root);
        return maxDiameter;
    }
};