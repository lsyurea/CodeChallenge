class DynamicSegmentTree {
public:
    struct seg_node {
        seg_node *left, *right;
        int val;
    }

    seg_node *node = new seg_node;

    void init(vector<int> &a, int left, int right) {
        if (left == right) {
            node->val = a[left - 1];
            return;
        }
        node->left = new seg_node;
        node->right = new seg_node;
        init(vec, node->left, left, (left + right) / 2);
        init(vec, node->right, (left + right) / 2 + 1, right);
        node->val = node->left->val + node->right->val;
    }

    void update(int left, int right, int idx, int val) {
        if (idx < left || right < idx)
            return;
        if (left == right) {
            node->val = val;
            return;
        }

        if (node->left == nullptr) {
            node->left = new seg_node;
        }
        if (node->right == nullptr) {
            node->right = new seg_node;
        }
        update(node->left, left, (left + right) / 2, idx, val);
        update(node->right, (left + right) / 2 + 1, right, idx, val);
        node->val = node->left->val + node->right->val;
    }

    int query(int l, int r) {
        return query(1, N, l, r);
    }

    int query(int left, int right, int l, int r) {
        if (r < left || right < l || node == nullptr)
            return 0;
        if (l <= left && right <= r)
            return node->val;
        return query(node->left, left, (left + right) / 2, l, r)
            + query(node->right, (left + right) / 2 + 1, right, l, r);
    }
};