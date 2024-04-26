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
    int minFallingPathSum(vector<vector<int>>& grid) {
        // iterate by the rows first
        vector<int> dp = grid[0];
        int r = grid.size(), c = grid[0].size();
        for (int i = 1; i < r; i++) {
            // add to the dp the values of that row
            // take the smallest value of prefix & suffix max
            int cur = dp[0], j;
            vector<int> prefix_min = vector(c, 0);
            vector<int> suffix_min = vector(c, 0);
            for (j = 0; j < c; j++){
                cur = min(cur, dp[j]);
                prefix_min[j] = cur;
            }
            cur = dp[c - 1];
            for (j = c - 1; j >=0; j--){
                cur = min(cur, dp[j]);
                suffix_min[j] = cur;
            }
            for (int k = 0; k < c; k++) {
                int cur = INT_MAX;
                if (k > 0) cur = min(prefix_min[k - 1], cur);
                if (k < c - 1) cur = min(suffix_min[k + 1], cur);
                dp[k] = grid[i][k] + cur;
            }
        }
        // get the min
        int min_val = dp[0];
        for (int i = 1; i < c; i++) min_val = min(min_val, dp[i]);
        return min_val;
    }
};