#include<bits/stdc++.h>
using namespace std;

// nodes on whose removal the graph breaks into two or more components
// modification of the tarjans algo

void dfs(int node, int parent, vector<int> adj[], vector<int>& vis, vector<int>& tin, vector<int>& low, 
            vector<int>& art, int& timer) {
        
    vis[node] = 1;
    low[node] = tin[node] = timer;
    timer++;
    int child = 0;
    for(auto nbr : adj[node]) {
        if(nbr == parent) continue;
        if(!vis[nbr]){
            dfs(nbr, node, adj, vis, tin, low, art, timer);
            low[node] = min(low[node], low[nbr]);
            if(low[nbr] >= tin[node] && parent != -1) art[node] = 1;
            child++;
        }
        else {
            low[node] = min(low[node], tin[nbr]);
        }
    }
    if(parent == -1 && child > 1) art[node] = 1;
}

vector<int> articulationPoints(int v, vector<int>adj[]) {
    vector<int> vis(v, 0);
    vector<int> tin(v);
    vector<int> low(v);
    vector<int> art(v, 0);
    int timer = 0;
    for(int i=0; i<v; i++) {
        if(!vis[v]) {
            dfs(i, -1, adj, vis, tin, low, art, timer);
        }
    }
    vector<int> ans;
    for(int i=0; i<v; i++) {
        if(art[i] == 1) ans.push_back(i);
    }
    if(ans.size() == 0) ans.push_back(-1);
    return ans;
}


