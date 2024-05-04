class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        // n log n solution
        int res = 0, l = 0, h = people.size() - 1;
        while (l <= h) {
            if (people[l] + people[h] <= limit) {
                l++;
            }
            h--;
            res++;
        }
        return res;
    }
};