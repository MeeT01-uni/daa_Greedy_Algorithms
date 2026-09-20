class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> count, ends;
        for (size_t i = 0; i < nums.size(); i++) count[nums[i]]++;
        for (size_t i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if (count[x] == 0) continue;
            if (ends[x-1] > 0) {
                ends[x-1]--;
                ends[x]++;
            } else if (count[x+1] > 0 && count[x+2] > 0) {
                count[x+1]--;
                count[x+2]--;
                ends[x+2]++;
            } else {
                return false;
            }
            count[x]--;
        }
        return true;
    }
};