class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        long long cost[2] = {0, 0};
        int n = nums.size();
        for (int parity = 0; parity < 2; parity++)
            for (int i = parity; i < n; i += 2) {
                int left  = (i - 1 >= 0) ? nums[i-1] : INT_MAX;
                int right = (i + 1 < n)  ? nums[i+1] : INT_MAX;
                int need = min(left, right) - 1;
                if (nums[i] > need) cost[parity] += nums[i] - need;
            }
        return (int)min(cost[0], cost[1]);
    }
};