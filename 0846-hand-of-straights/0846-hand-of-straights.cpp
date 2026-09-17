class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if ((int)hand.size() % groupSize != 0) return false;
        map<int,int> cnt;
        for (int c : hand) cnt[c]++;
        while (!cnt.empty()) {
            int start = cnt.begin()->first;
            for (int i = 0; i < groupSize; i++) {
                map<int,int>::iterator it = cnt.find(start + i);
                if (it == cnt.end()) return false;
                if (--(it->second) == 0) cnt.erase(it);
            }
        }
        return true;
    }
};