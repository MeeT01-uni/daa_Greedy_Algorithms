class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<int> st;
        int res = 0;
        for (size_t i = 0; i < arr.size(); i++) {
            while (!st.empty() && st[st.size()-1] <= arr[i]) {
                int mid = st[st.size()-1];
                st.pop_back();
                int left = st.empty() ? INT_MAX : st[st.size()-1];
                res += mid * min(left, arr[i]);
            }
            st.push_back(arr[i]);
        }
        while (st.size() > 1) {
            int a = st[st.size()-1];
            st.pop_back();
            res += a * st[st.size()-1];
        }
        return res;
    }
};