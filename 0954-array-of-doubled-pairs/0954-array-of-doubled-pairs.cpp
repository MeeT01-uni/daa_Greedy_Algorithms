class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int,int> cnt;
        for (size_t i = 0; i < arr.size(); i++) cnt[arr[i]]++;
        if (cnt[0] % 2 != 0) return false;
        cnt[0] = 0;
        vector<int> keys;
        for (map<int,int>::iterator it = cnt.begin(); it != cnt.end(); ++it)
            keys.push_back(it->first);
        sort(keys.begin(), keys.end(), [](int a, int b){ return abs(a) < abs(b); });
        for (size_t i = 0; i < keys.size(); i++) {
            int x = keys[i];
            if (cnt[x] == 0) continue;
            map<int,int>::iterator it = cnt.find(2*x);
            if (it == cnt.end() || it->second < cnt[x]) return false;
            it->second -= cnt[x];
            cnt[x] = 0;
        }
        return true;
    }
};