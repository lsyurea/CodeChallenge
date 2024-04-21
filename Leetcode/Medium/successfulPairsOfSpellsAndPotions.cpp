class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // sort the potions
        sort(potions.begin(), potions.end());
        int l = 0, r = potions.size() - 1, m;
        long long c;
        for (int i = 0; i < spells.size(); i++) {
            l = 0, r = potions.size() - 1;
            while (l < r) {
                m = l + (r - l) / 2;
                // cout << m << '\n';
                c = (long long) potions[m] * (long long) spells[i];
                if (c < success) {
                    // success == c in > m
                    l = m + 1;
                } else {
                    // success == c in <= m
                    r = m;
                }
            }
            if (l == potions.size() - 1 && success > (long long) potions[l] * (long long) spells[i]) spells[i] = 0;
            else spells[i] = potions.size() - l;
        }
        return spells;
    }
};