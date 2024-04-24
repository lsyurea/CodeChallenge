class Solution {
public:
    int maxRepeating(string sequence, string word) {
        // create a dp to represent idx of words;
        vector<int> dp(sequence.size(), 0);
        bool is_sub = true;
        int res = 0;
        for (int i = 0; i < sequence.size(); i++) {
            // either you take the starting letter or you dont
            if (i <= sequence.size() - word.size() && sequence[i] == word[0]) {
                // check if all the letter matches
                for (int j = 1; j < word.size(); j++) {
                    if (word[j] != sequence[i + j]) {
                        is_sub = false;
                        break;
                    }
                }
                if (is_sub) {
                    // always add the dp to the prev subproblems if current string matches
                    dp[i + word.size() - 1]++;
                    if (i > 0) dp[i + word.size() - 1] += dp[i - 1];
                }
                else is_sub = true;
            }

            // update res to the max val
            res = max(res, dp[i]);
        }
        // for (int i = 0; i < dp.size(); i++) cout << dp[i] << ' ';
        return res;
    }
};