class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i+1]) {
                int best = i + 1;
                for (int j = i + 1; j < n; j++)
                    if (arr[j] < arr[i] && arr[j] > arr[best]) best = j;
                swap(arr[i], arr[best]);
                break;
            }
        }
        return arr;
    }
};