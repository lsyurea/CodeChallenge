class Solution {
    
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // O(n) time with O(1) space
        // constraint is that the number is positive and starts from 1

        // mark the presence with - number
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            // if i + 1 is visited, push it into res.
            if (nums[abs(nums[i]) - 1] < 0) {
                res.push_back(abs(nums[i]));
            }
            // else mark it
            nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        }
        return res;
    }
};