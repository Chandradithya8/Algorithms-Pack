#include<bits/stdc++.h>
using namespace std;

// spanning tree -> a tree which has N nodes and N-1 edges and all nodes are reachable 
//                  from each other 

// minimum spanning tree ->  the spanning tree has the minimum sum of edge weights in 
//							 the graph


// prims algorithm - greedy approach
// O(E * log(E))
int spanningTree(int V, vector<vector<int>> adj[]) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>> pq;
    // weight | node | parent
    pq.push({0, {0, -1}});
    int totalSum = 0;
    vector<int> vis(V, 0);
    vector<pair<int, int>> final_edges; // will contain all the edges that are involved in 
     									//	the mst

    while(pq.size()) {
        auto top = pq.top();
        pq.pop();
        int wt = top.first;
        int node = top.second.first;
        int parent = top.second.second;
        
        if(vis[node]) continue;
        
        vis[node] = 1; 
        totalSum += wt;
        if(parent != -1) final_edges.push_back({node, parent});
        for(auto it : adj[node]) {
            int adjNode = it[0];
            int eWeight = it[1];
            pq.push({eWeight, {adjNode, node}});
        }
    }
    return totalSum;
}


// kruskals algo
// O(E * log(E)) -> sorting

class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<=n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node) {
        if(parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }
    
    void unionBySize(int u, int v) {
        int u_par = findParent(u);
        int v_par = findParent(v);
        if(u_par == v_par) return;
        
        if(size[u_par] < size[v_par]) {
            parent[u_par] = v_par;
            size[v_par] += size[u_par];
        }
        else {
            parent[v_par] = u_par;
            size[u_par] += size[v_par];
        }
    }
};

int SpanningTree(int V, vector<vector<int>> adj[]) {
    // weight | u | v
    vector<pair<int, pair<int, int>>> edges;
    for(int i=0; i<V; i++) {
        int u = i;
        for(auto it : adj[i]) {
            int v = it[0];
            int wt = it[1];
            edges.push_back({wt, {u, v}});
        }
    }
    
    int mstW = 0;
    sort(edges.begin(), edges.end());
    DisjointSet ds(V);
    for(auto it : edges) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        
        if(ds.findParent(u) != ds.findParent(v)) {
            mstW += wt;
            ds.unionBySize(u, v);
        }
    }
    return mstW;
}