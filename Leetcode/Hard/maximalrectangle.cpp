class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // Intuition everytime a zero is found
        // , split it into 2 different regions
        
        // memoise it
        unordered_map<int, unordered_map<int, 
            unordered_map<int, unordered_map<int, int>>>> mp;
        
        return maxRect(matrix, 0, matrix.size() - 1,
            0, matrix[0].size() - 1, mp);
    }

    bool is_in(int tr, int br, int tc, int bc, 
    unordered_map<int, unordered_map<int, 
            unordered_map<int, unordered_map<int, int>>>>& mp) {
        return mp.count(tr) && mp[tr].count(br) && mp[tr][br].count(tc) && mp[tr][br][tc].count(bc);
    }
    
    int maxRect(vector<vector<char>>& m, int tr, int br, int tc, 
    int bc, unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int, int>>>>& mp) {
        if (is_in(tr, br, tc, bc, mp)) return mp[tr][br][tc][bc];
        // iterate through everything and stop at the first 0
        for (int i = tr; i <= br; i++) {
            for (int j = tc; j <= bc; j++) {
                if (m[i][j] == '0') {
                    int v = 0;
                    if (i > tr) v = max(v, maxRect(m, tr, i - 1, tc, bc, mp));
                    if (i < br) v = max(v, maxRect(m, i + 1, br , tc, bc, mp));
                    if (j > tc) v = max(v, maxRect(m, tr, br, tc, j - 1, mp));
                    if (j < bc) v = max(v, maxRect(m, tr, br, j + 1, bc, mp));
                    mp[tr][br][tc][bc] = v;
                    return v;
                }
            }
        }
        // if everything is 1 return it
        return (br - tr + 1) * (bc - tc + 1);
    }
};