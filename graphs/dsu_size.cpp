struct DSU {
public:
    const int mod = 1e6;
    vector<long long> parent, size;
    DSU(int n) {
        parent.resize(n+1, 0);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++) {
            parent[i] = i;
        }
    }
    int findParent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    
    void combine(int u, int v) {
        u = findParent(u);
        v = findParent(v);
        if(size[u] < size[v]) {
            parent[u] = v;
            size[v] =  (size[v] + size[u])%mod;
        }
        else {
            parent[v] = u;
            size[u] = (size[u] + size[v])%mod;
        }
    }
};
