class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int> maxReach(time + 1, 0);
        for (size_t i = 0; i < clips.size(); i++) {
            int s = clips[i][0], e = clips[i][1];
            if (s <= time) maxReach[s] = max(maxReach[s], e);
        }
        int count = 0, curEnd = 0, farthest = 0;
        for (int i = 0; i < time; i++) {
            farthest = max(farthest, maxReach[i]);
            if (i == farthest) return -1;
            if (i == curEnd) { count++; curEnd = farthest; }
        }
        return count;
    }
};