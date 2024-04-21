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
    bool exist(vector<vector<char>>& board, string word) {
        int max_word_idx = word.size() - 1;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0] && isContained(board, word, i, j, max_word_idx)) return true;
            }
        }
        return false;
    }

    bool isContained(vector<vector<char>>& board, string word, int posIdxR, int posIdxC, int max_word_idx) {
        // create a visited array to check which has been visited 
        // starting from word at index 1
        vector<vector<bool>> visited = vector<vector<bool>>
            (board.size(), vector<bool>(board[0].size(), false));
        // do a dfs on the board by using recursion
        if (max_word_idx == 0) return true;
        return isValidPath(visited, board, posIdxR, posIdxC, 0, word, max_word_idx);
    }   

    bool isValidPath(vector<vector<bool>>& visited, vector<vector<char>>& board, int r, int c, int idx, string word, int max_word_idx) {
        if (idx == max_word_idx) return word[idx] == board[r][c];

        bool res = false;
        visited[r][c] = true;
        // top
        if (r > 0 && !visited[r - 1][c] && word[idx + 1] == board[r - 1][c])
            res = res || 
                isValidPath(visited, board, r - 1, c, idx + 1, word, max_word_idx);

        // bottom
        if (r < board.size() - 1 && !visited[r + 1][c] 
            && word[idx + 1] == board[r + 1][c]) 
            res = res ||
                isValidPath(visited, board, r + 1, c, idx + 1, word, max_word_idx);
        
        // left
        if (c > 0 && !visited[r][c - 1] && word[idx + 1] == board[r][c - 1])
            res = res || 
                isValidPath(visited, board, r, c - 1, idx + 1, word, max_word_idx);

        // right
        if (c < board[0].size() - 1 && !visited[r][c + 1] 
            && word[idx + 1] == board[r][c + 1])
            res = res ||
                isValidPath(visited, board, r, c + 1, idx + 1, word, max_word_idx);
        visited[r][c] = false;
        return res;
    }
};