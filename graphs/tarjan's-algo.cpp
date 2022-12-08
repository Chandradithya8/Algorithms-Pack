#include<bits/stdc++.h>
using namespace std;

// for finding bridges in a graph
// bridges -> an edge whose removal makes the graph into two or more components

vector<vector<int>> bridges;
int cnt = 0;
void dfs(int node, int parent, vector<int> adj[], vector<int>& vis, vector<int>& tin, vector<int>& low) {
    vis[node] = 1;
    low[node] = tin[node] = cnt;
    cnt++;
    for(auto it : adj[node]) {
        if(it == parent) continue;
        if(vis[it] == 0) {
            dfs(it, node, adj, vis, tin, low);
            low[node] = min(low[it], low[node]);
            if(low[it] > tin[node]) {
                bridges.push_back({it, node});
            }
        }
        else {
            low[node] = min(low[node], low[it]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    // tarjan's algorithm
    vector<int> adj[n];
    for(auto it : connections) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    
    vector<int> tin(n);
    vector<int> low(n);
    vector<int> vis(n, 0);
    dfs(0, -1, adj, vis, tin, low);
    
    return bridges;
}


