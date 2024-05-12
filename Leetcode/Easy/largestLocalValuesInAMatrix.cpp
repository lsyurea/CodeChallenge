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
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> res;
        for (int i = 1; i < grid.size() - 1; i++) {
            vector<int> cur;
            for (int j = 1; j < grid.size() - 1; j++) {
                int mx = 0;
                // find max within the 9 box
                for (int a = i - 1; a <= i + 1; a++) 
                    for (int b = j - 1; b <= j + 1; b++)
                        mx = max(mx, grid[a][b]);
                cur.push_back(mx);
            }
            res.push_back(cur);
        }
        return res;
    }
};