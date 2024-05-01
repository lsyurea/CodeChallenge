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
    unordered_map<int, int> dp;
    int numTrees(int n) {
        // 1-2-3 different from 3-2-1
        // left or right root does not matter since it is affected
        // by the numbers

        // problem reduced to just number of ways to arrange the numbers 
        // either there is only 1 root or there is 2 root. 
        // If there is 1 root it is just last or first
        // if it is 2 root, it is the rest;
        if (n == 1) return 1;
        if (dp.count(n)) return dp[n];
        dp[n] = 2 * numTrees(n - 1);
        for (int i = 1; i < n - 1; i++) {
            dp[n]+= numTrees(i) * numTrees(n - 1 - i);
        }
        return dp[n];
    }
};