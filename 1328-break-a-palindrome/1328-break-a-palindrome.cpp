class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();

        // A single character cannot be made non-palindromic
        if (n == 1) {
            return "";
        }

        // Check only the first half
        for (int i = 0; i < n / 2; i++) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }

        // All characters in the first half are 'a'
        // So change the last character to 'b'
        palindrome[n - 1] = 'b';

        return palindrome;
    }
};