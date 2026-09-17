class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());
        
        // Sort indices of nums2 by value ascending
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return nums2[a] < nums2[b];
        });
        
        vector<int> result(n);
        int lo = 0, hi = n - 1;
        
        // Walk nums1 ascending
        for (int i = 0; i < n; i++) {
            if (nums1[i] > nums2[idx[lo]]) {
                // Beats the smallest remaining nums2 value — assign here
                result[idx[lo]] = nums1[i];
                lo++;
            } else {
                // Can't win right now — dump on the largest remaining nums2 value
                result[idx[hi]] = nums1[i];
                hi--;
            }
        }
        
        return result;
    }
};