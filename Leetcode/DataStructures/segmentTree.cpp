class SegTree {
public:
    vector<long long> tree;
    int seg_tree_size, base_size;

    void init(vector<int>& a) {
        base_size = 1;
        while (base_size < a.size())
            base_size *= 2;
        seg_tree_size = 2 * base_size - 1;
        tree.resize(seg_tree_size, 0);
        for (int i = base_size, j = 0; j < a.size() && i < seg_size; i++, j++)
            tree[i] = a[j];
        for (int i = base_size - 1; i >= 0; i--)
            tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    }

    void update(int idx, int val) {
        idx += base_size;
        tree[idx] = val;
        while (idx > 0) {
            // start updating from the parent node
            idx = (idx - 1) / 2;
            tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
        }
    }

    long long sum(int l, int r) {
        return sum(l, r, 0, base_size, 0);
    }


    long long sum(int l, int r, int start, int end, int node) {
        if (start >= r || end <= l)
            return 0;
        if (start >= l && end <= r)
            return tree[node];
        int mid = start + (end - start) / 2;
        return sum(l, r, start, mid, 2 * node + 1) + sum(l, r, mid, end, 2 * node + 2);
    }
};