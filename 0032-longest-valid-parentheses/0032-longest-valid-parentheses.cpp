class Solution {
public:
    int longestValidParentheses(std::string s) {
        int max_len = 0;
        std::stack<int> st;
        st.push(-1); 
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i); // Update the base index for future valid substrings
                } else {
                    max_len = std::max(max_len, i - st.top());
                }
            }
        }
        return max_len;
    }
};