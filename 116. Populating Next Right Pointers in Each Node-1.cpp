/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
  vector<vector<Node *>> levels;
  Node *connect(Node *root) { return dfs(root, 0); }

  Node *dfs(Node *root, int level) {
    if (!root)
      return nullptr;
    if (level == levels.size())
      levels.push_back({root});
    else {
      levels[level].back()->next = root;
      levels[level].push_back(root);
    }
    dfs(root->left, level + 1);
    dfs(root->right, level + 1);
    return root;
  }
};