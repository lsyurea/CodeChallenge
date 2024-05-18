/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = [](){ 
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr); 
    return 'c'; 
}();
class Solution {
public:
    Solution(){
        DPSolver; 
    }
    int distributeCoins(TreeNode* root) {
        int res = 0;
        helper(root, &res);
        return res;
    }

    int helper(TreeNode* root, int* res) {
        if (!root) return 0;
        // the coins are either lacking or in excess
        // excess should be - and lacking should be +
        int l = helper(root->left, res), r = helper(root->right, res);
        // if either the left or the right is in excess, first transfer the values with cost accounted
        *res += abs(l) + abs(r);
        // then return what is necessary
        return -(root->val - l - r - 1);
    }
};