class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int right = -1, left = -1;
        
        // Left to right: track max so far, find last index that's smaller than max
        int maxSoFar = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (nums[i] < maxSoFar) {
                right = i;
            } else {
                maxSoFar = nums[i];
            }
        }
        
        // Right to left: track min so far, find last (leftmost) index that's larger than min
        int minSoFar = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > minSoFar) {
                left = i;
            } else {
                minSoFar = nums[i];
            }
        }
        
        if (right == -1) return 0; // already sorted, left will also be -1
        
        return right - left + 1;
    }
};