class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure we always perform binary search on the smaller array to minimize the search space
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;
        
        while (left <= right) {
            int partitionA = left + (right - left) / 2;
            int partitionB = (m + n + 1) / 2 - partitionA;
            
            // Handle edge cases where the partition is at the extreme ends
            int maxLeftA = (partitionA == 0) ? INT_MIN : nums1[partitionA - 1];
            int minRightA = (partitionA == m) ? INT_MAX : nums1[partitionA];
            
            int maxLeftB = (partitionB == 0) ? INT_MIN : nums2[partitionB - 1];
            int minRightB = (partitionB == n) ? INT_MAX : nums2[partitionB];
            
            // Check if we have found the correct partition
            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                // If total length is even
                if ((m + n) % 2 == 0) {
                    return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
                } 
                // If total length is odd
                else {
                    return max(maxLeftA, maxLeftB);
                }
            } 
            // If we are too far on the right side for partitionA, move left
            else if (maxLeftA > minRightB) {
                right = partitionA - 1;
            } 
            // If we are too far on the left side for partitionA, move right
            else {
                left = partitionA + 1;
            }
        }
        
        return 0.0;
    }
};