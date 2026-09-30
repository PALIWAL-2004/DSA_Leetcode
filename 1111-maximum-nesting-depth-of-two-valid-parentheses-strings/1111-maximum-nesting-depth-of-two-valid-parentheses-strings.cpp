class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int depth = 0;
        
        for (char c : seq) {
            if (c == '(') {
                // Assign to 0 or 1 based on current depth before incrementing
                ans.push_back(depth % 2);
                depth++;
            } else {
                // Decrement depth first, then assign to match its corresponding '('
                depth--;
                ans.push_back(depth % 2);
            }
        }
        
        return ans;
    }
};