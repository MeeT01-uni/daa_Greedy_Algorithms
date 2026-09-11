class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26, 0);
        
        // Store the last occurrence of every character
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        vector<bool> used(26, false);
        string st;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            // Already present in result
            if (used[ch - 'a']) {
                continue;
            }

            // Remove bigger characters if they appear later
            while (!st.empty() &&
                   st.back() > ch &&
                   last[st.back() - 'a'] > i) {
                
                used[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(ch);
            used[ch - 'a'] = true;
        }

        return st;
    }
};