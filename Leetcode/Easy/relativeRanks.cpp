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
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> dp = score;
        sort(score.begin(), score.end());
        unordered_map<int, int> v;
        for (int i = 0; i < score.size(); i++) {
            v[score[i]] = score.size() - i;
        }
        vector<string> res;
        for (int &d : dp) {
            if (v[d] == 1) {
                res.push_back("Gold Medal");
            } else if (v[d] == 2) {
                res.push_back("Silver Medal");
            } else if (v[d] == 3) {
                res.push_back("Bronze Medal");
            } else {
                res.push_back(to_string(v[d]));
            }
        }
        return res;
    }
};