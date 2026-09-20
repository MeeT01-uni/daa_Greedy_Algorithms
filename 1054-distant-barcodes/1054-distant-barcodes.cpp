class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int> cnt;
        for (size_t i = 0; i < barcodes.size(); i++) cnt[barcodes[i]]++;
        vector<pair<int,int> > freq;
        for (unordered_map<int,int>::iterator it = cnt.begin(); it != cnt.end(); ++it)
            freq.push_back(make_pair(it->second, it->first));
        sort(freq.begin(), freq.end(), greater<pair<int,int> >());
        int n = barcodes.size();
        vector<int> res(n);
        int idx = 0;
        for (size_t f = 0; f < freq.size(); f++) {
            int val = freq[f].second, c = freq[f].first;
            for (int k = 0; k < c; k++) {
                if (idx >= n) idx = 1;
                res[idx] = val;
                idx += 2;
            }
        }
        return res;
    }
};