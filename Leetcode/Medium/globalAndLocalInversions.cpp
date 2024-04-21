class Solution {
public:
    void FastIO() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    bool isIdealPermutation(vector<int>& nums) {
        int localInversionCount = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] > nums[i]) localInversionCount++;
        }
        return validateGlobalInversions(nums, 0, nums.size() - 1, localInversionCount) != -1;
    }

    int validateGlobalInversions(vector<int>& nums, int low, int high, int check) {
        if (low >= high) return 0;
        int mid = low + (high - low) / 2;
        int left = validateGlobalInversions(nums, low, mid, check);
        if (left == -1) return -1;
        int right = validateGlobalInversions(nums, mid + 1, high, check);
        if (right == -1) return -1;
        if (left > check || right > check - left) return -1;
        int count = mergeAndCount(nums, low, mid, high);
        if (count > check - left - right) return -1;
        return left + right + count;
    }

    int mergeAndCount(vector<int>& nums, int low, int mid, int high) {
        vector<int> newNums;
        int res = 0;
        int tempLow = low;
        int lowTwo = mid + 1;

        // if last element of left side smaller or equal to first element of right side
        if (nums[mid] <= nums[lowTwo]) {
            return res;
        }

        while (low <= mid && lowTwo <= high) {
            if (nums[low] <= nums[lowTwo]) {
                newNums.push_back(nums[low++]);
            } else {
                res += lowTwo - low;
                newNums.push_back(nums[lowTwo++]);
            }
        }

        while (low <= mid) {
            newNums.push_back(nums[low++]);
        }
        while (lowTwo <= high) {
            newNums.push_back(nums[lowTwo++]);
        }
        for (int i = tempLow; i <= high; i++) {
            nums[i] = newNums[i - tempLow];
        }
        return res;
    }
};