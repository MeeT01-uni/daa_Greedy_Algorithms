class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(),
             [](const vector<int>& a, const vector<int>& b){ return a[0] - a[1] < b[0] - b[1]; });
        int n = costs.size() / 2, total = 0;
        for (int i = 0; i < n; i++) total += costs[i][0];
        for (size_t i = n; i < costs.size(); i++) total += costs[i][1];
        return total;
    }
};