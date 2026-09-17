class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char c : tasks) freq[c - 'A']++;
        int maxFreq  = *max_element(freq.begin(), freq.end());
        int countMax = count(freq.begin(), freq.end(), maxFreq);
        long long slots = (long long)(maxFreq - 1) * (n + 1) + countMax;
        return max((long long)tasks.size(), slots);
    }
};