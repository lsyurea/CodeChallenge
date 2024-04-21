class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose then reverse
        int i, j, temp;
        // transpose
        for (i = 0; i < matrix.size(); i++) {
            for (j = 0; j < i; j++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        // reverse
        for (i = 0; i < matrix.size(); i++) {
            for (j = 0; j < matrix.size() / 2; j++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[i][matrix.size() - 1 - j];
                matrix[i][matrix.size() - 1 - j] = temp;
            }
        }
    }
};