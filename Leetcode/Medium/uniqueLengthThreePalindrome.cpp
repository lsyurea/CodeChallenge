#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    void FastIO() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    int countPalindromicSubsequence(string s) {
        // count number of subsequence of length 3
        // left and right element are the same & middle element can be anything
        int char_count[26] = {0};
        int res = 0;
        for (auto &ch: s) {
            if (char_count[(int)ch - 97] == 0) {
                char_count[(int)ch - 97] = 1;
                res += countPalindromeGivenChar(s, ch);
            }
        }
        return res;
    }

    int countPalindromeGivenChar(string s, char c) {

        int char_count[26] = {0};
        int global_count = 0;
        int local_count = 0;
        bool toggle = false;

        for (auto &ch: s) {
            if (ch == c && !toggle) {
                toggle = !toggle;
                continue;
            }
            if (ch == c && toggle) {
                global_count = local_count;
                if (char_count[(int)c - 97] == 0) {
                    char_count[(int)c - 97] = 1;
                    local_count++;
                };
                continue;
            }
            if (char_count[(int)ch - 97] == 0 && toggle) {
                char_count[(int)ch - 97] = 1;
                local_count++;
            }
        }
        return global_count;
    }
};

int main() {
    Solution* obj = new Solution();
    obj->FastIO();
    string s = "aabca";
    cout << obj->countPalindromicSubsequence(s) << "\n";
    return 0;
}