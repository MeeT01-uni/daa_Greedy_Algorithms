class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans;

        while (a > 0 || b > 0) {

            // If last two characters are "aa",
            // we cannot add another 'a'
            if (ans.size() >= 2 &&
                ans[ans.size() - 1] == 'a' &&
                ans[ans.size() - 2] == 'a') {

                ans += 'b';
                b--;
            }

            // If last two characters are "bb",
            // we cannot add another 'b'
            else if (ans.size() >= 2 &&
                     ans[ans.size() - 1] == 'b' &&
                     ans[ans.size() - 2] == 'b') {

                ans += 'a';
                a--;
            }

            // Otherwise use the character
            // that has more remaining
            else if (a >= b) {
                ans += 'a';
                a--;
            }

            else {
                ans += 'b';
                b--;
            }
        }

        return ans;
    }
};