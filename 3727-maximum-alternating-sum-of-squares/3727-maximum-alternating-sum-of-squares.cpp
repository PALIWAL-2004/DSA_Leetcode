class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sq(n);
        for (int i = 0; i < n; ++i) {
            sq[i] = 1LL * nums[i] * nums[i];
        }
        
        sort(sq.begin(), sq.end());
        
        long long ans = 0;
        int m = n / 2; // number of negative slots
        
        // Smallest m values are subtracted
        for (int i = 0; i < m; ++i) {
            ans -= sq[i];
        }
        // Remaining values are added
        for (int i = m; i < n; ++i) {
            ans += sq[i];
        }
        
        return ans;
    }
};