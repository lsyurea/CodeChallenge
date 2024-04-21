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
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len_str = strs.size();
        vector<int> ones = vector(len_str, 0), zeros = vector(len_str, 0);
        // convert into arrays of ones and zeros
        for (int i = 0; i < len_str ; i++) {
            for (auto &ch : strs[i]) {
                if (ch == '0') zeros[i]++;
                else ones[i]++;
            }
        }

        // let the dp represents an array of all possible integers m and n
        vector<vector<int>> dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        // in each items, update the array to the correct value
        for (int i = 0; i < len_str; i++) {
            for (int j = m; j >= 0; j--) {
                for (int k = n; k >= 0; k--) {
                    if (j >= zeros[i] && k >= ones[i]) 
                        dp[j][k] = max(dp[j - zeros[i]][k - ones[i]] + 1, dp[j][k]);
                }
            }
        }
        return dp[m][n];
    }
};