
class Solution {
public:
    long long minSumSquareDiff(std::vector<int>& nums1, std::vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long totalOps = (long long)k1 + k2;
        
        // Count frequencies of initial absolute differences
        std::unordered_map<int, long long> diffCount;
        long long initialSumSq = 0;
        int maxDiff = 0;
        
        for (int i = 0; i < n; ++i) {
            int d = std::abs(nums1[i] - nums2[i]);
            diffCount[d]++;
            if (d > maxDiff) {
                maxDiff = d;
            }
        }
        
        // Use a priority queue to process the largest differences first
        std::priority_queue<int> pq;
        for (auto& pair : diffCount) {
            pq.push(pair.first);
        }
        
        while (totalOps > 0 && !pq.empty()) {
            int curDiff = pq.top();
            pq.pop();
            
            if (curDiff == 0) break;
            
            long long count = diffCount[curDiff];
            // Operations needed to reduce all elements with `curDiff` down to the next available difference in `pq`
            long long nextDiff = pq.empty() ? 0 : pq.top();
            long long opsNeeded = count * (curDiff - nextDiff);
            
            if (totalOps >= opsNeeded) {
                totalOps -= opsNeeded;
                diffCount[nextDiff] += count;
                diffCount.erase(curDiff);
            } else {
                // We don't have enough operations to reduce all of them to nextDiff
                long long reduceBy = totalOps / count;
                long long remainder = totalOps % count;
                
                diffCount[curDiff] -= count;
                diffCount[curDiff - reduceBy] += (count - remainder);
                diffCount[curDiff - reduceBy - 1] += remainder;
                
                totalOps = 0;
                break;
            }
        }
        
        // Calculate the final minimum sum of squared differences
        long long minSumSq = 0;
        for (auto& pair : diffCount) {
            long long d = pair.first;
            long long count = pair.second;
            minSumSq += count * d * d;
        }
        
        return minSumSq;
    }
};