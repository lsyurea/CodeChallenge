class UnionFind {
    vector<int> root, rank;

public:
    UnionFind(int n) : root(n), rank(n) {
        rank.assign(n, 1);
        iota(root.begin(), root.end(), 0);
    }

    int Find(int x) {
        // path compression
        if (x == root[x])
            return x;
        else
            return root[x] = Find(root[x]);
    }

    void Union(int x, int y) {
        int rX = Find(x), rY = Find(y);
        if (rX == rY)
            return;
        // set the smaller tree root to be the larger tree
        if (rank[rX] > rank[rY])
            root[rY] = rX;
        if (rank[rX] == rank[rY])
            rank[rY]++;
    }
};