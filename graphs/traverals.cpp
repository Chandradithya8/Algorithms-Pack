#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    queue<int> q;
    q.push(0);
    unordered_map<int, bool> vis;
    vis[0] = true;
    vector<int> ans;
    while(q.size()) {
        auto front = q.front();
        q.pop();
        ans.push_back(front);
        for(auto it : adj[front]) {
            if(!vis[it]) {
                vis[front] = true;
                q.push(it);
            }
        }
    }
    return ans;
}


void dfs(int node, vector<int> adj[], unordered_map<int, bool>& vis, vector<int>& ans) {
    vis[node] = true;
    ans.push_back(node);
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(it, adj, vis, ans);
        }
    }
}

int main() {
	
}
