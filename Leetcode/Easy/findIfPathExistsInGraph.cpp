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
    // inefficient method of using graph traversal
    // bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    //     // dfs use stack
    //     // to ensure no loops, must have visited array
    //     vector<bool> visited = vector(n, false);
    //     vector<int> stk = vector({source});
    //     int cur;
    //     while (!stk.empty()) {
    //         cur = stk.back();
    //         stk.pop_back();
    //         if (cur == destination) return true;
    //         visited[cur] = true;
    //         // do a search from the edges
    //         for (auto edge: edges) {
    //             // from first to second
    //             if (edge[0] == cur && !visited[edge[1]]) {
    //                 stk.push_back(edge[1]);
    //             } 
    //             // from second to first
    //             if (edge[1] == cur && !visited[edge[0]]) {
    //                 stk.push_back(edge[0]);
    //             }
    //         }
    //     }
    //     return false;
    // }
};