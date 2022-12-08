#include<bits/stdc++.h>
using namespace std;

// dfs approach
bool dfs(int node, unordered_map<int, vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
    vis[node] = 1;
    pathVis[node] = 1;
    // check the adjacent node
    for(auto it : adj[node]) {
        if(!vis[it]) {
            if(dfs(it, adj, vis, pathVis)) return true;
        }
        // already visited and pathVisited
        else if(pathVis[it]) return true;
    }
    pathVis[node] = 0;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int,int>> & edges) {
    unordered_map<int, vector<int>> adj;
    // build the adj list
    for(auto it : edges) {
        adj[it.first].push_back(it.second);
    }
    vector<int> vis(n+1, 0);
    vector<int> pathVis(n+1, 0); // pathVis says which of the nodes are involved in the cycle
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            if(dfs(i, adj, vis ,pathVis)) return true;
        }
    }
    return false;
}