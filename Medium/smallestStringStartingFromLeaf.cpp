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
    string smallestFromLeaf(TreeNode* root) {
        return smallest(root, "");
    }

    string smallest(TreeNode* root, string s) {
        if (!root) return "";
        char v = (int) 'a' + root->val;
        s.push_back(v);
        if (!root->left && !root->right) return string(1, v);
        string prev_l, prev_r;
        if (!root->right) {
            prev_l = smallest(root->left, s);
            prev_l.push_back(v);
            return prev_l;
        }
        if (!root->left) {
            prev_r = smallest(root->right, s);
            prev_r.push_back(v);
            return prev_r;
        }

        prev_l = smallest(root->left, s);
        prev_r = smallest(root->right, s);
        int l = prev_l.length(), r = prev_r.length(), i, s_len = s.length();
        
        for (i = 0; i < min(l, r); i++) {
            if (prev_l[i] < prev_r[i]) {
                prev_l.push_back(v);
                return prev_l;
            }
            if (prev_l[i] > prev_r[i]) {
                prev_r.push_back(v);
                return prev_r;
            }
        }
        int iter = min(s_len, max(l, r) - min(l, r));
        for (i = 0; i < iter;i++) {
            if (l > r && prev_l[r + i] < s[s_len - i - 1]) {
                prev_l.push_back(v);
                return prev_l;
            }
            if (r > l && prev_r[l + i] < s[s_len - i - 1]) {
                prev_r.push_back(v);
                return prev_r;
            }
        }

        if (prev_l.length() < prev_r.length()) {
            if (prev_r[prev_l.length()] < v) {
                prev_r.push_back(v);
                return prev_r;
            }
            prev_l.push_back(v);
            return prev_l;
        }
        if (prev_l.length() > prev_r.length()) {
            if (prev_l[prev_r.length()] < v) {
                prev_l.push_back(v);
                return prev_l;
            }
            prev_r.push_back(v);
            return prev_r;
        }
        prev_r.push_back(v);
        return prev_r;
    }
};