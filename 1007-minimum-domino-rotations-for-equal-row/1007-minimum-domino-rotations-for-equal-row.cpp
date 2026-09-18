class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int best = -1;
        for (int target = 1; target <= 6; target++) {
            bool ok = true;
            int rotTop = 0, rotBot = 0;
            for (size_t i = 0; i < tops.size(); i++) {
                if (tops[i] != target && bottoms[i] != target) { ok = false; break; }
                if (tops[i] != target) rotTop++;
                if (bottoms[i] != target) rotBot++;
            }
            if (ok) {
                int cur = min(rotTop, rotBot);
                if (best == -1 || cur < best) best = cur;
            }
        }
        return best;
    }
};