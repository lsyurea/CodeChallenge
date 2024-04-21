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
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort the array to make it monotonically increasing
        sort(nums.begin(), nums.end());
        int l, r, n = nums.size(), t;
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            l = i + 1;
            r = n - 1;
            while (l < r) {
                t = nums[i] + nums[l] + nums[r];
                if (t < 0) {
                    l++;
                } else if (t > 0) {
                    r--;
                } else {
                    res.push_back(vector({nums[i], nums[l], nums[r]}));
                    // stop at the last num whr it is equal
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while(l < r && nums[r] == nums[r - 1]) r--;
                    // executes a ++ and -- to reach the next num 
                    // that is not equal
                    l++; r--;
                }
            }
            while (i + 1 < n && nums[i] == nums[i + 1]) i++;
        }
        return res;
    }
};