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
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> v(deadends.begin(), deadends.end());
        pair<string, int> c;
        // bfs and find target
        deque<pair<string, int>> deq;
        string cur;
        int len = target.length();
        for (int i = 0; i < len; i++) cur.push_back('0');
        deq.push_back({cur, 0});
        while (!deq.empty()) {
            c = deq.front();
            deq.pop_front();
            // if deadlock or visited
            if (v.count(c.first)) continue;
            // mark as visited
            v.insert(c.first);
            if (c.first == target) return c.second;
            // add the children
            for (int i = 0 ; i < len; i++) {
                int val = (int) c.first[i] + 1;
                if (val > (int) '9') val = (int) '0';
                char n = (char) val;
                // copy str
                string nxt = c.first;
                nxt[i] = n;
                if (!v.count(nxt))deq.push_back({nxt, c.second + 1});
                val = (int) c.first[i] - 1;
                if (val < (int) '0') val = (int) '9';
                n = (char) val;
                nxt = c.first;
                nxt[i] = n;
                if (!v.count(nxt))deq.push_back({nxt, c.second + 1});
            }
        }
        return -1;
    }
};
