class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        string cur;
        if (!nums.size()) return {};
        int prev = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1] + 1) {
                if (nums[i - 1] != prev) {
                    cur = to_string(prev);
                    cur.append("->");
                    cur.append(to_string(nums[i-1]));
                } else {
                    cur = to_string(prev);
                }
                res.push_back(cur);
                prev = nums[i];
            }
        }
        if (nums[nums.size() - 1] != prev) {
            cur = to_string(prev);
            cur.append("->");
            cur.append(to_string(nums[nums.size() - 1]));
        } else {
            cur = to_string(nums[nums.size() - 1]);
        }
        res.push_back(cur);
        return res;
    }
};