class Graph {
public:
  vector<vector<pair<int, int>>> adj;
  int n;
  Graph(int n, vector<vector<int>> &edges) {
    adj = vector<vector<pair<int, int>>>(n);
    this->n = n;
    for (auto &e : edges)
      adj[e[0]].push_back({e[1], e[2]});
  }

  void addEdge(vector<int> edge) { adj[edge[0]].push_back({edge[1], edge[2]}); }

  int shortestPath(int node1, int node2) {
    vector<int> dist(n, INT_MAX / 2);
    using P = pair<int, int>;
    // min heap;
    priority_queue<P, vector<P>, greater<P>> pq;

    dist[node1] = 0;
    pq.push({0, node1});
    while (!pq.empty()) {
      auto [cost, u] = pq.top();
      pq.pop();
      if (cost > dist[u])
        continue;
      if (u == node2)
        return cost;
      for (auto [v, c] : adj[u])
        if (cost + c < dist[v]) {
          dist[v] = cost + c;
          pq.push({dist[v], v});
        }
    }

    return -1;
  }
};