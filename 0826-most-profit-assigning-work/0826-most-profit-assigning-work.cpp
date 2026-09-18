class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int,int> > jobs(n);
        for (int i = 0; i < n; i++) jobs[i] = make_pair(difficulty[i], profit[i]);
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        int i = 0, best = 0, total = 0;
        for (size_t w = 0; w < worker.size(); w++) {
            while (i < n && jobs[i].first <= worker[w]) { best = max(best, jobs[i].second); i++; }
            total += best;
        }
        return total;
    }
};