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
    string removeKdigits(string num, int k) {
        // speed up edge cases
        int num_len = num.length(); int tgt_len = num_len - k, j = 0;
        if (tgt_len == 0) return "0";
        string res;
        for (int i = 0; i < num_len; i++) {
            while (k > 0 && j > 0 && res.back() > num[i]) {
                k--; res.pop_back(); j--;
            }
            res.push_back(num[i]); j++;
        }
        k = 0;
        while (res[k] == '0' && k < tgt_len - 1) k++;
        return res.substr(k, tgt_len - k);
    }
};