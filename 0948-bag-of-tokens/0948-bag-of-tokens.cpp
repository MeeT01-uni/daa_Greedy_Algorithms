class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int lo = 0, hi = (int)tokens.size() - 1, score = 0, best = 0;
        while (lo <= hi) {
            if (power >= tokens[lo]) {
                power -= tokens[lo++];
                score++;
                best = max(best, score);
            } else if (score > 0) {
                power += tokens[hi--];
                score--;
            } else break;
        }
        return best;
    }
};