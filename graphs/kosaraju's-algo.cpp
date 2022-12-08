#include<bits/stdc++.h>
using namespace std;

// strongly connected components -> valid only for directed graphs

// sort all the edges according to the finishing time
// reverse the graph
// do a dfs

void findOrder(int node, vector<int> adj[], stack<int>& st, vector<int>& vis) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it]) findOrder(it, adj, st, vis);
    }
    st.push(node);
}

void dfs(int node, vector<int> adj1[], vector<int>& vis) {
    vis[node] = 1;
    for(auto it : adj1[node]) {
        if(!vis[it]) dfs(it, adj1, vis);
    }
}

int kosarajuAlgo(int v, vector<vector<int>> &edges) {
	vector<int> adj[v];
    for(auto it : edges) {
        adj[it[0]].push_back(it[1]);
    }
    stack<int> st;
    vector<int> vis(v, 0);
    for(int i=0; i<v; i++) {
        if(!vis[i]) {
            findOrder(i, adj, st, vis);
        }
    }
    
    // reverse the graph
    vector<int> adj1[v];
    for(auto it : edges) {
        adj1[it[1]].push_back(it[0]);
    }
    vis.clear();
    vis.resize(v, 0);
    
    // do dfs
    int cnt = 0;
    while(st.size()) {
        int top = st.top();
        st.pop();
        if(!vis[top]) {
            cnt++;
            dfs(top, adj1, vis);
        }
    }
    return cnt;
}