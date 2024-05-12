class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // from the back find the number smaller than me and replace it
        for (int i = nums.size() - 2; i >= 0; i--) {
            for (int j = nums.size() - 1; j >= i + 1; j--)
                if (nums[j] > nums[i]) {
                    // swap the values
                    int temp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = temp;
                    // afterwards do ascending sort from j + 1 to i
                    sort(nums.begin() + i + 1, nums.end());
                    return;
                }
        }
        // do reversal
        reverse(nums.begin(), nums.end());
    }
};