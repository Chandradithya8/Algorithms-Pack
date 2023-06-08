// Problem - https://leetcode.com/problems/second-minimum-time-to-reach-destination/

// unequal weights - priority queue
vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);
dist1[0] = 0;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
q.push({0, 0});

while(q.size()) {
    auto front = q.top();
    q.pop();
    int node = front.first;
    int cost = front.second;

    for(auto it : adj[node]) {
      int new_cost = cost + it[1];
      if(new_cost < dist1[it[0]]) {
        dist2[it[0]] = dist1[it[0]];
        dist1[it[0]] = new_cost;
        q.push({it[0], dist1[it[0]]});
      }
      else if(new_cost > dist1[it[0]] and new_cost < dist2[it[0]]) {
        dist2[it[0]] = new_cost;
        q.push({it[0], dist2[it[0]]});
      }
    }
}

// equal weights - queue
vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);
dist1[0] = 0;

queue<pair<int, int>> q;
q.push({0, 0});

while(q.size()) {
    auto front = q.front();
    q.pop();
    int node = front.first;
    int cost = front.second;

    for(auto it : adj[node]) {
      int new_cost = cost + 1;
      if(new_cost < dist1[it[0]]) {
        dist2[it[0]] = dist1[it[0]];
        dist1[it[0]] = new_cost;
        q.push({it[0], dist1[it[0]]});
      }
      else if(new_cost > dist1[it[0]] and new_cost < dist2[it[0]]) {
        dist2[it[0]] = new_cost;
        q.push({it[0], dist2[it[0]]});
      }
    }
}
