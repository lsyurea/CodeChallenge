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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int a, b, c = nums.size();
        long d, e;
        vector<vector<int>> r;
        for (int i = 0; i < c; i++) {
            for (int j = i + 1; j < c; j++) {
                a = j + 1;
                b = c - 1;
                while (a < b) {
                    d = nums[a] + nums[b];
                    e = nums[j] + nums[i];
                    if (d > target - e) b--;
                    else if (d < target - e) a++; 
                    else {
                        r.push_back(
                            vector({nums[a], nums[b], nums[j], nums[i]}));
                        while (a < b && nums[a] == nums[a + 1]) a++;
                        while (a < b && nums[b] == nums[b - 1]) b--;
                        a++;
                        b--;
                    }
                }
                while (j + 1 < c && nums[j] == nums[j + 1]) j++;
            }
            while (i + 1 < c && nums[i] == nums[i + 1]) i++;
        }
        return r;
    }
};