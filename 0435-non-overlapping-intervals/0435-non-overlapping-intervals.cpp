class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b){ return a[1] < b[1]; });
        int removed = 0, prevEnd = intervals[0][1];
        for (size_t i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= prevEnd) prevEnd = intervals[i][1];
            else removed++;
        }
        return removed;
    }
};