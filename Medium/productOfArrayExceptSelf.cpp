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
    vector<int> productExceptSelf(vector<int>& nums) {
        // create a prefix and suffix
        int p = 1, i;
        vector<int> ans;
        // iterate thru the loop to update the values
        for (i = 0; i < nums.size(); i++) {
            // multiply the corresponding indices with the prefix and suffix first before updating its values
            // to exclude the multiple at that index
            ans.push_back(p);
            p*=nums[i];
        }
        p = 1;
        for (i = nums.size() - 1; i >=0; i--) {
            ans[i]*=p;
            p*=nums[i];
        }
        // to make it faster by seperating the loops
        return ans;
    }
};