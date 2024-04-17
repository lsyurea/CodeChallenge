class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // take previous and current
        vector<int> p = vector(text1.length() + 1, 0);
        vector<int> c = vector(text1.length() + 1, 0);

        // in each char of text2
        for (int i = 1; i <= text2.length(); i++) {
            // if the current character is reached from text 1
            // update the char at that text
            for (int j = 1; j <= text1.length(); j++) {    
                if (text1[j - 1] == text2[i - 1]) {
                    // if current is the same, current is prev + 1 or 
                    c[j] = p[j - 1] + 1;
                } else {
                    c[j] = max(c[j - 1], p[j]);
                }
            }
            p = c;
        }
        for (int k = 0; k < c.size(); k++) cout << c[k] << '\n';
        return c[text1.length()];
    }
};