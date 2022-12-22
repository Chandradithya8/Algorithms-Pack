vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int>adj[N];
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> dist(N, INT_MAX);
        dist[src] = 0;
        queue<int> q;
        q.push(src); // node parent
        
        vector<int> vis(N, 0);
        while(q.size()) {
            auto node = q.front();
            q.pop();
            for(auto child : adj[node]) {
                if(!vis[child]) {
                    vis[child] = 1;
                    dist[child] = min(dist[child], dist[node]+1);
                    q.push(child);
                }
            }
        }
        for(int i=0; i<N; i++) {
            if(dist[i] == INT_MAX) dist[i] = -1;
        }
        return dist;
    }
