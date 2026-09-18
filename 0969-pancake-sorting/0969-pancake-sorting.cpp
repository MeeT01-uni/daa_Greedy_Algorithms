class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        int n = arr.size();
        for (int size = n; size > 1; size--) {
            int maxIdx = 0;
            for (int i = 0; i < size; i++)
                if (arr[i] > arr[maxIdx]) maxIdx = i;
            if (maxIdx == size - 1) continue;
            if (maxIdx > 0) {
                reverse(arr.begin(), arr.begin() + maxIdx + 1);
                res.push_back(maxIdx + 1);
            }
            reverse(arr.begin(), arr.begin() + size);
            res.push_back(size);
        }
        return res;
    }
};