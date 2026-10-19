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
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*, int>>q;
        long long sum = 0;
        long long max_sum = INT_MIN;
        int item = 1;
        int value = 0;
        q.push({root,1});
        while(!q.empty()){
            auto temp = q.front();
            TreeNode* t1 = temp.first;
            int v = temp.second;
            q.pop();

            if(v>item){
               if(sum>max_sum){
                value = item;
                max_sum = sum;
               }
                item = v;
                sum = 0;
            }
            sum = sum + t1->val;
            if(t1->left) q.push({t1->left,v+1});
            if(t1->right) q.push({t1->right,v+1});
        }
        if(sum>max_sum){
            value=item;
            max_sum = sum;
        }
        return value;
    }
};