class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> cnt;
        for (int a : answers) cnt[a]++;
        int total = 0;
        for (unordered_map<int,int>::iterator it = cnt.begin(); it != cnt.end(); ++it) {
            int groupSize = it->first + 1;
            int groups = (it->second + groupSize - 1) / groupSize;
            total += groups * groupSize;
        }
        return total;
    }
};