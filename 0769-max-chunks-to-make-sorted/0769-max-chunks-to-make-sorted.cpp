class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks = 0, mx = 0;
        for (int i = 0; i < (int)arr.size(); i++) {
            mx = max(mx, arr[i]);
            if (mx == i) chunks++;
        }
        return chunks;
    }
};