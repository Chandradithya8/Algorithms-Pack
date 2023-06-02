#include<bits/stdc++.h>
using namespace std;

// applicable for negative egdes
// helps for finding negative weight cycles

// applicable for directed and undirected but can find negative cycles only for directed graph

//single source shortest path algorithm

// O(v * E)
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    vector<int> dist(V, 1e8);
    dist[S] = 0;
    for(int i=0; i<V-1; i++) {
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // do one more iteration to check if it has negative weight cycle
    for(auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(dist[u] != 1e8 && dist[u] + wt < dist[v]) return {-1};
    }

    return dist;
}

int main() {
	
}
