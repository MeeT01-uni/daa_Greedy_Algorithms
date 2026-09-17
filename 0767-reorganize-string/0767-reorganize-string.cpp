class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        int maxFreq = 0, letter = 0;
        for (int i = 0; i < 26; i++)
            if (freq[i] > maxFreq) { maxFreq = freq[i]; letter = i; }
        int n = s.size();
        if (maxFreq > (n + 1) / 2) return "";
        string res(n, ' ');
        int idx = 0;
        while (freq[letter] > 0) { res[idx] = 'a' + letter; idx += 2; freq[letter]--; }
        for (int i = 0; i < 26; i++)
            while (freq[i] > 0) {
                if (idx >= n) idx = 1;
                res[idx] = 'a' + i;
                idx += 2;
                freq[i]--;
            }
        return res;
    }
};