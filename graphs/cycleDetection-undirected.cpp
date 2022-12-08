#include<bits/stdc++.h>
using namespace std;

// cycle detection dfs
bool flag = false;

void dfs(int i, vector<int> adj[], int parent, unordered_map<int, bool>& vis) {
    vis[i] = 1;
    for(auto it : adj[i]) {
        if(!vis[it]) {
            dfs(it, adj, i, vis);
        }
        else if(vis[it] && it != parent) {
            flag = true;
            return;
        }
    }
}


// cycle detection bfs
bool isCycle(int V, vector<int> adj[]) {
    unordered_map<int, bool> vis;
    for(int i=0; i<V; i++) {
        if(!vis[i]) {
            queue<pair<int, int>> q;
            vis[i] = 1;
            q.push({i, -1});
            while(q.size()) {
                auto it = q.front();
                q.pop();
                int node = it.first;
                int parent = it.second;
                for(auto n : adj[node] ) {
                    if(!vis[n]) {
                        vis[n] = 1;
                        q.push({n, node});
                    }
                    else if(vis[n] && n != parent) return true;
                }
            }
        }
    }
    return false;
}

int main() {
	
}
