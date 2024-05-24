class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        // this problem can be reduced to 0/1 knapsack with the scores
        // either u use or u dont use
        vector<int> cnt = vector(26, 0);
        for (char c : letters) 
            cnt[c - 'a']++;
        return helper(words, 0, cnt, score, 0);

    }
    int helper(vector<string>& words, int idx, vector<int>& letters, vector<int>& scr, int res) {
        if (idx == words.size()) return res;
        vector<int> used_letters = letters;
        bool is_valid = true;
        int ret = res;
        for (char c : words[idx]) {
            used_letters[c - 'a']--;
            ret += scr[c - 'a'];
            if (used_letters[c - 'a'] < 0) {
                is_valid = false;
                break;
            }
        }
        if (!is_valid) return helper(words, idx + 1, letters, scr, res);
        return max(helper(words, idx + 1, letters, scr, res), 
            helper(words, idx + 1, used_letters, scr, ret));
    }
};