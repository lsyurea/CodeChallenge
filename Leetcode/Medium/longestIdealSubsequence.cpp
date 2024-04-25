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
    int longestIdealString(string s, int k) {
        // s is always lower case
        // stores the last elem of the longest substr
        vector<int> dp(26, 0);
        int res = 0, cur;
        // n^2 solution is too slow
        // 26n = n solution is feasible
        for (int i = 0; i < s.length(); i++) {
            cur = s[i] - 'a';
            dp[cur]++;
            // note that k is <= 26
            for (int j = max(0, cur - k); j <= min(25,cur + k); j++) {
                if (j != cur)
                    dp[cur] = max(dp[j] + 1, dp[cur]);
            }
            res = max(res, dp[cur]);
        }
        return res;
    }
};