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
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return sum_helper(root, 0);
    }
    int sum_helper(TreeNode* root, int val) {
        if (root == nullptr) return 0;
        int c = val * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) return c;
        return sum_helper(root->left, c) + sum_helper(root->right, c);
    }
};