class SegTree {
public:
    int N = 0;
    vector<int> st;

    void init(vector<int>& a) {
        N = a.size();
        st.resize(2 * N + 1);
        for (int i = 0; i < N; i++) 
            st[N + i] = a[i];
        for (int i = N - 1; i > 0; i--) 
            st[i] = st[i << 1] + st[(i << 1) + 1];
    }

    void update(int idx, int val) {
        idx += N;
        st[idx] = val;
        for (idx >>= 1; idx > 0; idx >>= 1) 
            st[idx] = st[idx << 1] + st[(idx << 1) + 1];
    }

    int query(int l, int r) {
        int res = 0;
        for (l += N, r += N; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) res += st[l++];
            if (!(r & 1)) res += st[r--];
        }
        return res;
    }
};