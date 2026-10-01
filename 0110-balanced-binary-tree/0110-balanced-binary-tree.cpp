class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // If the helper function returns -1, the tree is unbalanced.
        return checkHeight(root) != -1;
    }

private:
    int checkHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0; // Base case: height of a null node is 0
        }

        // Check left subtree
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1; // Propagate the imbalance upward

        // Check right subtree
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1; // Propagate the imbalance upward

        // If the current node is unbalanced, return -1
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        // Return the height of the current node
        return max(leftHeight, rightHeight) + 1;
    }
};