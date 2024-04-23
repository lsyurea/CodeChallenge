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
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // edge case
        if (n==1) return {0};
        // create deg vector
        vector<int> deg(n, 0);
        // create adjacency matrix
        vector<vector<int>> adj(n);
        // add the relevant edges to adjacency matrix and the degree
        for (auto& e : edges) {
            int v = e[0], w = e[1];
            adj[v].push_back(w);
            adj[w].push_back(v);
            deg[v]++;
            deg[w]++;
        }
        // keep track of the leaves
        queue<int> q; 
        // add the starting leaves
        for (int i = 0; i < n; i++) {
            if (deg[i] == 1)
                q.push(i);
        }
        // declare vector for ans
        vector<int> ans;

        // check the remaining nodes
        int remaining = n;
        // as there are still leaves
        while (!q.empty()) {
            // find remaining without leaves
            // use it for later iteration
            int q_size = q.size();
            remaining -= q_size;
            // do a search on the leaves and update it to the next leave
            for (int i = 0; i < q_size; i++) {
                // get the current value
                int v = q.front();
                q.pop();
                // if there is nothing remaining, all the current values 
                // are the middle nodes
                if (remaining == 0) ans.push_back(v);
                // in each leaves only add the next leaves
                for (int w : adj[v]) {
                    if (--deg[w] == 1)// remove edge connecting to v
                        q.push(w);
                }
            }
        }
        return ans;
    }
};
