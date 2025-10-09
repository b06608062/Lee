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
  Node *cloneGraph(Node *node) {
    if (!node)
      return nullptr;

    unordered_map<Node *, Node *> umap;
    stack<Node *> st;

    umap[node] = new Node(node->val);
    st.push(node);
    while (!st.empty()) {
      Node *cur = st.top();
      st.pop();
      for (auto &nei : cur->neighbors) {
        if (!umap.count(nei)) {
          umap[nei] = new Node(nei->val);
          st.push(nei);
        }
        umap[cur]->neighbors.push_back(umap[nei]);
      }
    }

    return umap[node];
  }
};