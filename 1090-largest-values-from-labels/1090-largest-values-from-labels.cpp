class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        vector<pair<int,int> > items(n);
        for (int i = 0; i < n; i++) items[i] = make_pair(values[i], labels[i]);
        sort(items.begin(), items.end(), greater<pair<int,int> >());
        unordered_map<int,int> used;
        int total = 0, taken = 0;
        for (int i = 0; i < n && taken < numWanted; i++) {
            int lab = items[i].second;
            if (used[lab] < useLimit) {
                used[lab]++;
                total += items[i].first;
                taken++;
            }
        }
        return total;
    }
};