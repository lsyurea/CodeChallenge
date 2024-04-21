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
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper((unsigned char) n - 1, (unsigned char)n, res, "(");
        return res;
    }

    void helper(unsigned char l, unsigned char r, vector<string>& res, string cur) {
        if (l == 0 && r == 0) res.push_back(cur);
        if (l != r && r != 0) helper(l, r - 1, res, cur + ')');
        if (l != 0) helper(l - 1, r, res, cur + '(');
    }
};