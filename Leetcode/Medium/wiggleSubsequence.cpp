class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // invariant is such that to lengthen wiggle,
        // always replace smallest with smalles and largest with larger
        if (nums.size() == 1) return 1;

        // first 2 numbers must be different
        int a = nums[0], b, l = 1;
        bool has_second = false;
        for (int i = 1; i < nums.size(); i++) {
            if (!has_second && a == nums[i]) continue;
            if (!has_second && a != nums[i]) {
                has_second = true;
                b = nums[i];
                l++;
                continue;
            }
            // if a is larger
            if (a > b) {
                // b is also smaller than the next element
                if (b < nums[i]) {
                    a = b;
                    b = nums[i];
                    l++;
                } else {
                    //b is larger than the next element
                    b = nums[i];
                }
            } else if (a < b){
                // b is also larger than the next element
                if (b > nums[i]) {
                    a = b;
                    b = nums[i];
                    l++;
                } else {
                    b = nums[i];
                }
            }
        }
        return l;
    }
};