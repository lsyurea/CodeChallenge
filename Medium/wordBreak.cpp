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
    
    bool wordBreak(string s, vector<string>& wordDict) {
        // s -> wordDict (dp problem)
        // this dp contains all possible length that can be filled with worddict
        int str_len = s.length(), dict_len = wordDict.size();
        vector<int> dp = vector(str_len + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < str_len + 1; i++) {
            for (int j = 0; j < dict_len; j++) {
                string cur = wordDict[j];
                int cur_len = cur.length();
                if (i >= cur_len) {
                    if (s.substr(i - cur_len, cur_len) == cur) {
                        dp[i] = max(dp[i - cur_len], dp[i]);
                    }
                }
            }
        }
        return dp[str_len] == 1;
    }
};