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

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), len_nums = nums.size();
        
        if (sum % 2 == 1) return false;
        sum = sum / 2;
        // either you include each element in nums or not 
        // 0/1 knapsack
        vector<int> total = vector(sum + 1, 0);
        total[0] = 1;
        for (int i = 1; i < len_nums; i++) {
            // must reverse
            for (int j = sum; j >= 0; j--) {
                if (j >= nums[i - 1]) {
                    total[j] = max(total[j - nums[i - 1]], total[j]);
                }
            }
        }
        for (int i = 0; i < sum + 1; i++) {
            cout << total[i];
        }
        return total[sum] == 1;
    }
};