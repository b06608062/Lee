class Node {
public:
  bool val;
  bool isLeaf;
  Node *topLeft;
  Node *topRight;
  Node *bottomLeft;
  Node *bottomRight;

  Node() {
    val = false;
    isLeaf = false;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight,
       Node *_bottomLeft, Node *_bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

class Solution {
public:
  Node *construct(vector<vector<int>> &grid) {
    int n = grid.size();
    return helper(grid, n, 0, 0);
  }

  Node *helper(vector<vector<int>> &grid, int sz, int i, int j) {
    if (sz == 1)
      return new Node(grid[i][j], true);
    bool all_zero = true, all_one = true;
    for (int ii = i; ii < i + sz; ++ii)
      for (int jj = j; jj < j + sz; ++jj)
        if (grid[ii][jj] == 0)
          all_one = false;
        else
          all_zero = false;
    if (all_zero)
      return new Node(0, true);
    if (all_one)
      return new Node(1, true);
    int h_sz = sz / 2;
    Node *t_l = helper(grid, h_sz, i, j);
    Node *t_r = helper(grid, h_sz, i, j + h_sz);
    Node *b_l = helper(grid, h_sz, i + h_sz, j);
    Node *b_r = helper(grid, h_sz, i + h_sz, j + h_sz);
    return new Node(0, false, t_l, t_r, b_l, b_r);
  }
};

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node*
_bottomLeft, Node* _bottomRight) { val = _val; isLeaf = _isLeaf; topLeft =
_topLeft; topRight = _topRight; bottomLeft = _bottomLeft; bottomRight =
_bottomRight;
    }
};
*/

class Solution {
public:
  Node *construct(vector<vector<int>> &grid) {
    int n = grid.size();
    vector<vector<int>> pref(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] +
                     grid[i - 1][j - 1];
    return helper(grid, pref, n, 0, 0);
  }

  Node *helper(vector<vector<int>> &grid, vector<vector<int>> &pref, int sz,
               int i, int j) {
    if (sz == 1)
      return new Node(grid[i][j], true);
    int i_1 = i + 1, j_1 = j + 1, i_2 = i + sz, j_2 = j + sz;
    int pref_sum = pref[i_2][j_2] - pref[i_2][j_1 - 1] - pref[i_1 - 1][j_2] +
                   pref[i_1 - 1][j_1 - 1];
    if (pref_sum == 0)
      return new Node(0, true);
    if (pref_sum == sz * sz)
      return new Node(1, true);
    int h_sz = sz / 2;
    Node *t_l = helper(grid, pref, h_sz, i, j);
    Node *t_r = helper(grid, pref, h_sz, i, j + h_sz);
    Node *b_l = helper(grid, pref, h_sz, i + h_sz, j);
    Node *b_r = helper(grid, pref, h_sz, i + h_sz, j + h_sz);
    return new Node(0, false, t_l, t_r, b_l, b_r);
  }
};