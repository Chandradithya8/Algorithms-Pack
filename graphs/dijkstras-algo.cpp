#include<bits/stdc++.h>
using namespace std;

// not applicable for negative weights

// using priority queue - kind of a greedy approach
// if we use a queue instead of pq then we will be computing for unnecessary paths
//  dist node
// [[10, 3], [4, 3]] if this case if we use pq then we will take [4, 3] first 
// but in normal queue we will first take [10, 3] compute the dist and then take [4, 3]
// and update the dist  --->   unneccessary computation

//single source shortest path algorithm

// O(E * log(V)) time
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);
    dist[S] = 0;
    pq.push({0, S});
    
    while(pq.size()) {
        auto top = pq.top();
        pq.pop();
        int dst = top.first;
        int node = top.second;
        for(auto it : adj[node]) {
            int adjWeight = it[1];
            int adjNode = it[0];
            if(dst + adjWeight < dist[adjNode]) {
                dist[adjNode] = dst + adjWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

// using set
// O(E * log(V)) time
vector <int> dijkstras(int V, vector<vector<int>> adj[], int S) {
    set<pair<int, int>> s;
    vector<int> dist(V, INT_MAX);
    dist[S] = 0;
    s.insert({0, S});
    
    while(s.size()) {
        auto front = *(s.begin());
        int node = front.second;
        int dis = front.first;
        s.erase(front);
        for(auto it : adj[node]) {
            int adjNode = it[0];
            int adjWeight = it[1];
            if(dis + adjWeight < dist[adjNode]) {
                // if already visited then remove that {dist, node} from the set
                if(dist[adjNode] != INT_MAX) {
                    s.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = dis + adjWeight;
                s.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}


// print the shortest path
vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    int src = 1;
    int dest = n; // destination
    vector<pair<int, int>> adj[n+1];
    for(auto it : edges) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n+1, INT_MAX);
    vector<int> parent(n+1);
    for(int i=0; i<=n; i++) parent[i] = i;
    
    pq.push({0, src});
    dist[src] = 0;
    
    while(pq.size()) {
        auto top = pq.top();
        pq.pop();
        
        int node = top.second;
        int dis = top.first;
        for(auto it : adj[node]) {
           int adjNode = it.first;
           int adjWeight = it.second;
           if(dis + adjWeight < dist[adjNode]) {
               dist[adjNode] = dis + adjWeight;
               pq.push({dist[adjNode], adjNode});
               parent[adjNode] = node;
           }
        }
    }
    if(dist[dest] == INT_MAX) return {-1};

    // printing the path
    vector<int> ans;
    int node = dest;
    while(parent[node] != node) {
        ans.push_back(node);
        node = parent[node];
    }
    ans.push_back(src);
    reverse(ans.begin(), ans.end());
    return ans;
}

// number of shortest ways to reach the destination
// src - 0
// dest - n-1

int countPaths(int n, vector<vector<int>>& roads) {
    // similar to print the shortest path
    long long mod = 1000000007;
    vector<pair<long long, long long>> adj[n];
    for(auto it : roads) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    vector<long long> dist(n, LONG_LONG_MAX);
    vector<long long> ways(n, 0);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});
    
    while(pq.size()) {
        auto top = pq.top();
        pq.pop();
        long long dis = top.first;
        long long node = top.second;
        
        for(auto it : adj[node]) {
            long long adjNode = it.first;
            long long eWeight = it.second;
            if((dis + eWeight)%mod < dist[adjNode]) {
                dist[adjNode] = (dis + eWeight)%mod;
                pq.push({dist[adjNode], adjNode});
                ways[adjNode] = ways[node];
            }
            else if(dis + eWeight == dist[adjNode]) {
                ways[adjNode] = (ways[adjNode] + ways[node])%mod;
            }
        }
    }
    return ways[n-1]%mod;
}
