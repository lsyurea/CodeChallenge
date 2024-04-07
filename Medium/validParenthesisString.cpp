class Solution {
public:
    bool checkValidString(string s) {
        int left = 0,  dif = 0;
        // since ( is before ), number of (, * must be larger than or equal to ), *
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') left++;
            else if (s[i] == ')') left--;
            else dif++;
            if (left < 0) {
                if (dif <= 0) return false;
                dif--;
                left++;
            }
        }
        if (left > dif) return false;
        left = 0, dif = 0;
        for (int j = s.length() - 1; j >= 0; j--) {
            if (s[j] == ')') left++;
            else if (s[j] == '(') left--;
            else dif++;
            if (left < 0) {
                if (dif <= 0) return false;
                dif--;
                left++;
            }
        }
        return left <= dif;
    }
};