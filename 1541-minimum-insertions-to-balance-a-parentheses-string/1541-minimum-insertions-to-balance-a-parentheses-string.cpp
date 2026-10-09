class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int openBrackets = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                openBrackets++;
            } else {
                // We encountered a right parenthesis ')'
                // Check if there is another ')' right after it
                if (i + 1 < s.length() && s[i + 1] == ')') {
                    i++; // Skip the next ')' as it forms a pair with s[i]
                } else {
                    // We need to insert one ')' to make a consecutive pair
                    insertions++;
                }
                
                // Match this pair of ')' with an opening bracket '('
                if (openBrackets > 0) {
                    openBrackets--;
                } else {
                    // If no open bracket available, we need to insert a '('
                    insertions++;
                }
            }
        }
        
        // Any remaining unmatched opening brackets need two ')' each
        insertions += openBrackets * 2;
        
        return insertions;
    }
};