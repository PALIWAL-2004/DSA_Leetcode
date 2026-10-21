#include <string>
#include <algorithm>

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        
        // Check if already sorted
        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }
        
        // If length is 2 and not sorted, it's impossible
        if (n == 2) {
            return -1;
        }
        
        char min_char = *min_element(s.begin(), s.end());
        char max_char = *max_element(s.begin(), s.end());
        
        // If min char appears at the beginning or max char at the end (proper substring)
        if (s[0] == min_char || s[n - 1] == max_char) {
            return 1;
        }
        
        // Check for 3 operations case
        // If the unique max is at the beginning and the unique min is at the end
        if (s[0] == max_char && s[n - 1] == min_char) {
            int max_count = count(s.begin(), s.end(), max_char);
            int min_count = count(s.begin(), s.end(), min_char);
            if (max_count == 1 && min_count == 1) {
                return 3;
            }
        }
        
        // Most other cases take 2 operations
        return 2;
    }
};