#include<bits/stdc++.h>
using namespace std;

// topo sort - always occurs in directed acyclic graph
// linear ordering of vertices such that if there is an edge between u and v,
// u always occurs before v in that ordering.

// there can be multiple topo sort ordering


// dfs approach
void dfs(int node, unordered_map<int, vector<int>>& adj, int vis[], stack<int>& st) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(it, adj, vis, st);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, vector<int>> adj;

    // build the adj
    for(auto it : edges) {
        adj[it[0]].push_back(it[1]);
    }
    int vis[v] = {0};
    stack<int> st;
    for(int i=0; i<v; i++) {
        if(!vis[i]) {
            dfs(i, adj, vis, st);
        }
    }
    vector<int> ans;
    while(st.size()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}


// bfs approach - kahn's algorithm
vector<int> topoSort(int v, vector<int> adj[]) {
    vector<int> indegree(v, 0);
    for(int i=0; i<v; i++) {
        for(auto it : adj[i]) {
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0; i<v; i++){
        if(indegree[i] == 0) q.push(i);
    }
    vector<int> ans;
    while(q.size()) {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        
        for(auto it : adj[front]) {
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    return ans;
}

// if the ans.size() == v then it does not have a cycle
// else it has a cycle