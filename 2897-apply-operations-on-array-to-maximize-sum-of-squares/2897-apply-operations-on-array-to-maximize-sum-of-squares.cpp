#include <vector>

class Solution {
public:
    int maxSum(std::vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        std::vector<int> bitCount(31, 0);

        // Count frequency of 1s at each bit position
        for (int x : nums) {
            for (int bit = 0; bit < 31; ++bit) {
                if ((x >> bit) & 1) {
                    bitCount[bit]++;
                }
            }
        }

        long long ans = 0;

        // Greedily build the k largest elements
        for (int step = 0; step < k; ++step) {
            long long current = 0;
            for (int bit = 0; bit < 31; ++bit) {
                if (bitCount[bit] > 0) {
                    current |= (1LL << bit);
                    bitCount[bit]--;
                }
            }
            ans = (ans + (current % MOD) * (current % MOD)) % MOD;
        }

        return ans;
    }
};