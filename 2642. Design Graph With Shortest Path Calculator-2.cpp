// mark
// 1811
// Floyd-Warshall + 動態更新最短路徑
// 加入新 edge(u, v, w) 後，保證 dis[i][u] & dis[v][j] 已經是當前最短路徑
class Graph {
public:
  vector<vector<long long>> dis;
  int n;
  Graph(int n, vector<vector<int>> &edges) {
    this->n = n;

    dis.resize(n, vector<long long>(n, INT_MAX));
    for (int i = 0; i < n; i++)
      dis[i][i] = 0;
    for (vector<int> edge : edges)
      dis[edge[0]][edge[1]] = edge[2];

    for (int k = 0; k < n; ++k)
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  }

  void addEdge(vector<int> edge) {
    int u = edge[0], v = edge[1], w = edge[2];
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        dis[i][j] = min(dis[i][j], dis[i][u] + w + dis[v][j]);
  }

  int shortestPath(int node1, int node2) {
    if (dis[node1][node2] == INT_MAX)
      return -1;

    return dis[node1][node2];
  }
};