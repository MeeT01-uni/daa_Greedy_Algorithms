class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int result = 0;
        int curMin = arrays[0][0];
        int curMax = arrays[0].back();
        
        for (int i = 1; i < arrays.size(); i++) {
            int lo = arrays[i][0];
            int hi = arrays[i].back();
            
        
            result = max(result, abs(hi - curMin));
            result = max(result, abs(curMax - lo));
            
            
            curMin = min(curMin, lo);
            curMax = max(curMax, hi);
        }
        
        return result;
    }
};