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
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        // similar to find largest rectangle
        vector<vector<int>> res;
        vector<int> cur;
        int r, c;
        for (int i = 0; i < land.size(); i++) {
            for (int j = 0; j < land[0].size(); j++) {
                // check for 1s and do while loop
                if (land[i][j] == 1) {
                    cur = vector({i, j});
                    r = i;
                    c = j;
                    // rectangular and not square
                    // no adjacent invariant
                    land[i][j] = 0;
                    while (r < land.size() - 1 && land[r + 1][c]) {
                        r++;
                        land[r][c] = 0;
                    }
                    while (c < land[0].size() - 1 && land[r][c + 1]) {
                        c++;
                        for (int a = i; a <= r; a++)
                            land[a][c] = 0;
                    }
                    // add the coordinates
                    cur.push_back(r);
                    cur.push_back(c);
                    res.push_back(cur);
                }
            }
        }
        return res;
    }
};