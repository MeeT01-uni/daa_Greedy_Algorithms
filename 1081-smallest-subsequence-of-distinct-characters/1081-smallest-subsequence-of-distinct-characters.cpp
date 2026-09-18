class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26, -1), inStack(26, 0);
        for (int i = 0; i < (int)s.size(); i++) last[s[i] - 'a'] = i;
        string st;
        for (int i = 0; i < (int)s.size(); i++) {
            int c = s[i] - 'a';
            if (inStack[c]) continue;
            while (!st.empty() && st[st.size()-1] > s[i] && last[st[st.size()-1] - 'a'] > i) {
                inStack[st[st.size()-1] - 'a'] = 0;
                st.erase(st.size() - 1, 1);
            }
            st.push_back(s[i]);
            inStack[c] = 1;
        }
        return st;
    }
};