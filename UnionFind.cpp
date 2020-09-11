class DSU {
    vector<int> v;
    int size;
public:
    DSU(int n) {
        v.resize(n);
        size = n;
        iota(v.begin(), v.end(), 0);
    }
    int find(int i) {
        return v[i] == i ? i : v[i] = find(v[i]); // update the table!
    }
    void join(int i, int j) {
        int pi = find(i), pj = find(j);
        if (pi != pj) {
            v[pi] = pj;
            size--;
        }
    } 
    int get_size() {
        return size;
    }
};


#include <bits/stdc++.h>
using namespace std;

// ----------------DSU----------------

class DSU {
    vector<int> p;
public:
    DSU(int n) : p(n) {
        for (int i = 0; i < n; i++)
            p[i] = i;
    }
    void uni(int x, int y) {
        p[find(x)] = p[find(y)];
    }
    int find(int x) {
        if (p[x] != x)
            p[x] = find(p[x]);
        return p[x];
    }
};

// ----------------Version 3.0-----------------

class DSU {
    vector<int> p, size;
public:
    int root;
    DSU(int n) : p(n), size(n, 1) {
        for (int i = 0; i < n; i++)
            p[i] = i;
    }
    int uni(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return 0;
        int ret = 0;
        if (x == find(root)) ret += size[y] - 1;
        else if (y == find(root)) ret += size[x];
        if (size[x] >= size[y]) {
            size[x] += size[y];
            p[y] = x;
        } else {
            size[y] += size[x];
            p[x] = y;
        }
        return ret;
    }
    int find(int x) {
        if (p[x] != x)
            p[x] = find(p[x]);
        return p[x];
    }
};

// ----------------Version 2.0-----------------

class UnionFind {
private:
    vector<int> p;
    vector<int> r;
public: 
    explicit UnionFind(int n) : p(n), r(n) { iota(begin(p), end(p), 0); }; // p[i] = i
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]); 
    }
    bool uni(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return false;
        if (r[pu] == r[pv]) {
            p[pu] = pv;
            ++r[pu];
        } else if (r[pu] < r[pv])
            p[pu] = pv;
        else p[pv] = pu;
        return true;
    }
};
