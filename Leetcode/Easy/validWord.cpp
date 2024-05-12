class Solution {
public:
    bool isValid(string word) {
        int vowel = 0;
        int consonant = 0;
        unordered_set<char> v = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for (char &c : word) {
            if (isalpha(c)) {
                if (v.count(c)) vowel++;
                else consonant++;
            } else {
                int dig = c - '0';
                if (dig < 0 || dig > 9) return false;
            }
        }
        return vowel >= 1 && consonant >= 1 && word.size() >= 3;
    }
};