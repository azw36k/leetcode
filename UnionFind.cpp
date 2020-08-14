class UF {
    vector<int> p;
    vector<int> r;
public:
    UF(int n) : r(n + 1, 0), p(n + 1, 0) {
        for (int i = 0; i < p.size(); i++)
            p[i] = i;
    }
    bool union(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return false;
        if (r[pv] < r[pu])
            p[pv] = pu;
        else if (r[pu] < r[pv])
            p[pu] = pv;
        else {
            p[pv] = pu;
            r[pu] += 1;
        }
    }
    int find(int u) {
        if (u != p[u])
            p[u] = find(p[u]);
        return p[u];
    }
}