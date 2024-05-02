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

    int findMaxK(vector<int>& nums) {
        // use a dp of constant size to store the values
        // 0 for -1000, 1000 for 0, 2000 for 1000
        vector<int> dp = vector(2001, 0);
        int res = -1;
        for (int &num: nums) {
            if (dp[-num + 1000]) res = max(res, abs(num));
            dp[1000 + num] = 1;
        }
        return res;
    }
};