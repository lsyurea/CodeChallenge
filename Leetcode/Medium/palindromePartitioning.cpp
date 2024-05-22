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
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res = part(s);
        int i = 1;
        while (i < res.size()) { 
            bool is_palindrome = true;  
            for (int j = 0; j < res[i].size(); j++) {
                string c = res[i][j];
                int l = 0, r = c.length() - 1;
                while (l < r) {
                    if (c[l++] != c[r--]) {
                        is_palindrome = false;
                        break;
                    }
                }
                if (!is_palindrome) break;
            }
            if (!is_palindrome) res.erase(next(res.begin(), i));
            else i++;
        }
        return res;
    }

    vector<vector<string>> part(string s) {
        if (s.length() <= 1) return {{s}};
        vector<vector<string>> prev = part(s.substr(0, s.length() - 1));
        // either add to the last or add a new one
        int sze = prev.size();
        for (int i = 0; i < sze; i++) {
            vector<string> nxt = prev[i];
            string cur = nxt.back();
            cur.push_back(s.back());
            nxt[nxt.size() - 1] = cur;
            prev.push_back(nxt);
            prev[i].push_back(string(1, s.back()));
        }
        return prev;
    }
};