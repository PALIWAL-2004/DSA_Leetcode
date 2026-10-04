class Solution {
public:
    bool checkValidString(string s) {
        int min_open = 0; // Minimum possible open '('
        int max_open = 0; // Maximum possible open '('
        
        for (char c : s) {
            if (c == '(') {
                min_open++;
                max_open++;
            } else if (c == ')') {
                min_open--;
                max_open--;
            } else { // c == '*'
                min_open--; // Treat '*' as ')'
                max_open++; // Treat '*' as '('
            }
            
            // If the maximum possible open '(' is less than 0, there are too many ')'
            if (max_open < 0) {
                return false;
            }
            
            // The minimum open '(' cannot be negative
            min_open = max(0, min_open);
        }
        
        // If min_open is 0, all '(' have been successfully matched
        return min_open == 0;
    }
};