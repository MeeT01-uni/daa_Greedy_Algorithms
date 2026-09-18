class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long moves = 0;
        for (size_t i = 1; i < nums.size(); i++)
            if (nums[i] <= nums[i-1]) {
                moves += nums[i-1] + 1 - nums[i];
                nums[i] = nums[i-1] + 1;
            }
        return (int)moves;
    }
};