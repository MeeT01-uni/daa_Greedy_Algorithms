class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        
        // last[d] = last index where digit d appears
        vector<int> last(10, -1);
        for (int i = 0; i < n; i++) {
            last[s[i] - '0'] = i;
        }
        
        for (int i = 0; i < n; i++) {
            // Try to find the largest digit (9 down to current+1) that appears after i
            for (int d = 9; d > s[i] - '0'; d--) {
                if (last[d] > i) {
                    // Found a bigger digit later in the string, swap it in
                    swap(s[i], s[last[d]]);
                    return stoi(s);
                }
            }
        }
        
        return num; // no beneficial swap found
    }
};