class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        long long hold = LLONG_MIN / 4, cash = 0;
        for (size_t i = 0; i < prices.size(); i++) {
            long long nh = max(hold, cash - prices[i]);
            long long nc = max(cash, hold + prices[i] - fee);
            hold = nh; cash = nc;
        }
        return (int)cash;
    }
};