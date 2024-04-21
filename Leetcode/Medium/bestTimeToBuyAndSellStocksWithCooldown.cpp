#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = [](){ 
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr); 
    return 'c'; 
}();

class Solution {
public:
    Solution(){
        DPSolver; 
    }
    int maxProfit(vector<int>& prices) {
        // either buy the stock, dont buy or (sell stock and cannot buy for 1 day)
        // buy stock == need sell first
        // if negative is bought if positive is sold
        int prices_len = prices.size();
        vector<int> dp = vector(prices_len, 0);
        for (int i = 0; i < prices_len - 1; i++) {
            for (int j = i + 1; j < prices_len; j++) {
                int cur_profit = prices[j] - prices[i];
                if (i > 1) cur_profit = max(cur_profit, cur_profit + dp[i - 2]);
                dp[j] = max(max(cur_profit, dp[j]), dp[j - 1]); 
            }
        }
        return dp[prices_len - 1];
    }
};