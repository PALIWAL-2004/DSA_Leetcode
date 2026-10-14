#include <string>
#include <algorithm>

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // If the maximum possible sum with 'num' digits is less than 'sum', 
        // or if sum is greater than what 9s can provide, it's impossible.
        if (sum < 0 || (long long)num * 9 < sum) {
            return "";
        }
        
        string res = "";
        for (int i = 0; i < num; ++i) {
            // We want to pick the largest possible digit for the current position
            // such that the remaining sum can still be formed by the remaining positions.
            int max_possible = sum;
            int min_needed = 0;
            
            // Remaining digits after this one
            int rem_slots = num - 1 - i;
            
            // Max digit we can put here without starving the remaining slots
            int digit = sum - rem_slots * 9;
            if (digit < 0) digit = 0;
            if (digit > 9) digit = 9;
            
            // Wait, to maximize the score, we actually want the largest digits 
            // at the beginning! Let's re-verify the greedy condition:
            // Since we want to make the number as large as possible (and since 
            // higher digits contribute more to the sum of squares), we should 
            // greedily take min(9, remaining_sum) as long as the remaining sum 
            // does not exceed rem_slots * 9.
        }
        
        // Correct greedy logic:
        string ans = "";
        long long current_sum = sum;
        
        for (int i = 0; i < num; ++i) {
            int rem_slots = num - 1 - i;
            // The maximum digit we can place here is 9, 
            // but we must leave enough sum for the remaining slots (at most 9 per slot).
            int take = current_sum - rem_slots * 9;
            if (take < 0) take = 0;
            if (take > 9) take = 9;
            
            // To maximize the sum of squares, we actually want to prefer placing 
            // larger digits earlier. Let's check how much we can greedily take:
            // Actually, standard greedy from left to right:
            // We want the highest possible digit at the current position.
            // The maximum valid digit we can place here is min(9LL, current_sum), 
            // provided that the remaining sum can fit in the remaining slots.
            int d = min(9LL, current_sum);
            if (current_sum - d > (long long)rem_slots * 9) {
                // If taking 'd' leaves too much sum for remaining slots, we must take more? 
                // Wait, if current_sum - d > rem_slots * 9, it means 'd' is too small! 
                // We need to take a larger digit if possible, but 'd' is already min(9, current_sum).
                // Ah, if current_sum > rem_slots * 9, then current_sum - rem_slots * 9 is the MINIMUM 
                // digit we must take to consume the excess sum!
            }
            
            int low = max(0LL, current_sum - (long long)rem_slots * 9);
            int high = min(9LL, current_sum);
            
            // Since we want the lexicographically largest number (to maximize score/value),
            // we should pick the highest possible digit in [low, high].
            int chosen = high;
            ans += to_string(chosen);
            current_sum -= chosen;
        }
        
        return ans;
    }
};