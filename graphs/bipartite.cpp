#include<bits/stdc++.h>
using namespace std;

// linear graph with no cycle is always bipartite
// graph with even cycle length is always bipartite

// if a node is not colored then color it
// if a node is already colored then check whether the color is correct


// bfs approach
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> colored(n, -1);
    for(int i=0; i<n; i++) {
        if(colored[i] == -1) {
            queue<pair<int, int>> q;
            q.push({i, 0});
            colored[i] = 0;
            while(q.size()) {
                auto it = q.front();
                q.pop();
                int node = it.first;
                int color = it.second;
                for(auto ad : graph[node]) {
                    if(colored[ad] == -1) {
                        colored[ad] = !color;
                        q.push({ad, !color});
                    }
                    else if(colored[ad] == color) return false;
                }
            }
        }
    }
    return true;
}

// dfs approach
bool flag = true;
void dfs(int node, int color, vector<vector<int>>& graph, vector<int>& colored) {
    colored[node] = color;
    for(auto ad : graph[node]) {
        if(colored[ad] == -1) {
            dfs(ad, !color, graph, colored);
        }
        else if(colored[ad] == color) flag = false;
    }
}

bool isBipartiteDfs(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> colored(n, -1);
    for(int i=0; i<n; i++) {
        if(colored[i] == -1) {
            dfs(i, 0, graph, colored);
            if(!flag) return false;
        }
    }
    return true;
}

int main() {
	
}
