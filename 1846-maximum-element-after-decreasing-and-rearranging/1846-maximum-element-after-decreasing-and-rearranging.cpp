class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int prev = 0;
        for (size_t i = 0; i < arr.size(); i++) prev = min(arr[i], prev + 1);
        return prev;
    }
};