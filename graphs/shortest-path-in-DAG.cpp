#include<bits/stdc++.h>
using namespace std;

// shortest distance from the source to the current node

// compute the topo sort
// pop the stack until you have src on the top
// update the dis when you get a better distance

void dfs(int node, vector<pair<int,int>> adj[], int vis[], stack<int>& st) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it.first]) {
            dfs(it.first, adj, vis, st);
        }
    }
    st.push(node);
}

vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
    int src = 0; // given
    vector<pair<int,int>> adj[N];
    for(auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        adj[u].push_back({v, wt});
    }
    
    // find the topo sort
    int vis[N] = {0};
    stack<int> st;
    for(int i=0; i<N; i++) {
        if(!vis[i]) {
            dfs(i, adj, vis, st);
        }
    }
    vector<int> dist(N, INT_MAX);
    dist[src] = 0;
    while(st.top() != src) st.pop(); // pop the stack until the src is found
    
    while(st.size()) {
        int node = st.top();
        st.pop();
        for(auto it : adj[node]) {
            int v = it.first;
            int wt = it.second;
            dist[v] = min(dist[node]+wt, dist[v]);
        }
    }
    for(int i=0; i<N; i++) {
        if(dist[i] == INT_MAX) dist[i] = -1;
    }
    return dist;
}

int main() {
	
}
