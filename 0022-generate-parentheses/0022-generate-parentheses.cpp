class Solution {
public:
    void backtrack(vector<string>& result, string current, int open, int close, int max) {
        // Base case: if the current string length is 2 * max, it's a valid combination
        if (current.length() == max * 2) {
            result.push_back(current);
            return;
        }
        
        // If we haven't used all opening brackets, we can add one
        if (open < max) {
            backtrack(result, current + "(", open + 1, close, max);
        }
        
        // If we have more opening brackets than closing brackets, we can add a closing one
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, max);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};