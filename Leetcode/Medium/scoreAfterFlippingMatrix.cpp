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
    int matrixScore(vector<vector<int>>& grid) {
        // largest value first row must be 1
        for (int i = 0; i < grid.size(); i++) {
            if (grid[i][0] == 0) {
                // swap
                for (int j = 0; j < grid[0].size(); j++) {
                    grid[i][j] = (grid[i][j] + 1) % 2;
                }
            }
        }
        int res = pow(2, grid[0].size() - 1) * grid.size();

        // within the column, there must be more 1 than 0s
        for (int j = 1; j < grid[0].size(); j++) {
            int num_zero = 0, i;
            for (i = 0; i < grid.size(); i++) {
                if (grid[i][j] == 0) num_zero++;
            }
            res += pow(2, grid[0].size() - 1 - j) * 
                max(num_zero, (int) grid.size() - num_zero);
        }
        return res;
    }
};