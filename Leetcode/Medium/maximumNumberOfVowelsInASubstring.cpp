class Solution {
public:
    int maxVowels(string s, int k) {
        int m = 0, c = 0, i;
        // set up initial current number of vowels of k elements
        for (i = 0; i < k; i++) 
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i'
                || s[i] == 'o' || s[i] == 'u') c++;
        // for efficiency
        if (c == k) return k;
        // make current max to be c
        m = c;

        for (i = 0; i < s.size() - k; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i'
                || s[i] == 'o' || s[i] == 'u') c--;
            if (s[i + k] == 'a' || s[i + k] == 'e' 
                || s[i + k] == 'i'|| s[i + k] == 'o' 
                || s[i + k] == 'u') c++;
            m = max(c, m);
        }
        return m;

    }
};