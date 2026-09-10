class Solution {
public:
    int integerReplacement(int n) {
        long num = n; // use long to avoid overflow when n = INT_MAX and we add 1
        int steps = 0;
        
        while (num != 1) {
            if (num % 2 == 0) {
                num /= 2;
            } else {
                // odd case: check last two bits
                if (num == 3 || (num % 4) == 1) {
                    num -= 1;
                } else {
                    num += 1;
                }
            }
            steps++;
        }
        
        return steps;
    }
};