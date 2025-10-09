class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
public:
  unordered_map<Node *, Node *> umap;
  Node *cloneGraph(Node *node) {
    umap[nullptr] = nullptr;

    return dfs(node);
  }

  Node *dfs(Node *node) {
    if (umap.count(node))
      return umap[node];

    Node *cloneNode = new Node(node->val);
    umap[node] = cloneNode;
    for (auto &nei : node->neighbors)
      cloneNode->neighbors.push_back(dfs(nei));

    return cloneNode;
  }
};