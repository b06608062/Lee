class UnionFind {
  vector<int> parent, size;

public:
  UnionFind(int n) {
    parent.resize(n);
    size.resize(n, 1);
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
  }

  int find(int node) {
    if (parent[node] != node) {
      parent[node] = find(parent[node]);
    }
    return parent[node];
  }

  bool unionSets(int u, int v) {
    int pu = find(u), pv = find(v);
    if (pu == pv)
      return false;
    if (size[pu] < size[pv])
      swap(pu, pv);
    size[pu] += size[pv];
    parent[pv] = pu;
    return true;
  }
};

class Solution {
  vector<vector<int>> mst;
  set<int> mstEdges, pseudoCriticalEdges;
  vector<int> path;
  int destination;

public:
  vector<vector<int>>
  findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges) {
    mst.resize(n);
    vector<array<int, 4>> edgeList;
    for (int i = 0; i < edges.size(); ++i) {
      edgeList.push_back({edges[i][2], edges[i][0], edges[i][1], i});
    }
    sort(edgeList.begin(), edgeList.end());

    UnionFind uf(n);
    for (auto &[w, u, v, idx] : edgeList) {
      if (uf.unionSets(u, v)) {
        mst[u].push_back(idx);
        mst[v].push_back(idx);
        mstEdges.insert(idx);
      }
    }

    for (int i = 0; i < edges.size(); ++i) {
      if (mstEdges.count(i))
        continue;
      path.clear();
      destination = edges[i][1];
      if (dfs(edges[i][0], -1, edges)) {
        for (int p : path) {
          if (edges[p][2] == edges[i][2]) {
            pseudoCriticalEdges.insert(p);
            pseudoCriticalEdges.insert(i);
          }
        }
      }
    }

    vector<int> critical;
    for (int e : mstEdges) {
      if (!pseudoCriticalEdges.count(e))
        critical.push_back(e);
    }

    return {critical, vector<int>(pseudoCriticalEdges.begin(),
                                  pseudoCriticalEdges.end())};
  }

  bool dfs(int node, int parent, vector<vector<int>> &edges) {
    if (node == destination)
      return true;
    for (int &edgeIdx : mst[node]) {
      if (edgeIdx == parent)
        continue;
      path.push_back(edgeIdx);
      int next =
          edges[edgeIdx][0] == node ? edges[edgeIdx][1] : edges[edgeIdx][0];
      if (dfs(next, edgeIdx, edges))
        return true;
      path.pop_back();
    }
    return false;
  }
};