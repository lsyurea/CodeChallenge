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
    int trap(vector<int>& height) {
        // get the maximum from left to right and maxium from right to left
        // find the minimum of the two and sum them up
        int s = height.size(), i, p = 0, r = 0;
        vector<int> dp = vector(s, 0);
        // preprocessing
        for (i = 0; i < s; i++) {
            p = max(p, height[i]);
            dp[i] = p;
        }
        p = 0;
        for (i = s - 1; i >= 0; i--) {
            p = max(p, height[i]);
            r += min(dp[i], p) - height[i];
        }
        return r;
    }
};