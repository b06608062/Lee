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

    return helper(grid, 0, 0, grid.size());
  }

  Node *helper(vector<vector<int>> &grid, int i, int j, int size) {
    if (size == 1)
      return new Node(grid[i][j], true);

    int half = size / 2;
    Node *topLeft = helper(grid, i, j, half);
    Node *topRight = helper(grid, i, j + half, half);
    Node *BottomLeft = helper(grid, i + half, j, half);
    Node *BottomRight = helper(grid, i + half, j + half, half);

    if (topLeft->isLeaf && topRight->isLeaf && BottomLeft->isLeaf &&
        BottomRight->isLeaf && (topLeft->val == topRight->val) &&
        (topRight->val == BottomLeft->val) &&
        (BottomLeft->val == BottomRight->val)) {
      int val = topLeft->val;
      delete topLeft;
      delete topRight;
      delete BottomLeft;
      delete BottomRight;
      return new Node(val, true);
    }

    return new Node(0, false, topLeft, topRight, BottomLeft, BottomRight);
  }
};