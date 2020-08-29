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
    void uni(int x, int y) 
        p[find(x)] = p[find(y)];
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
