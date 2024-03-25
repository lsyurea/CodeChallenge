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
    int rob(vector<int>& nums) {
        int minus_two = 0, minus_one = 0, temp = 0;
        for (int i = 0; i < nums.size(); i++) {
            temp = minus_one;
            minus_one = max(minus_two + nums[i], minus_one);
            minus_two = temp;
        }
        return max(minus_two, minus_one);
    }
};