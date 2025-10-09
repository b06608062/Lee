// Segment Tree

struct SegTreeNode {
  int start, end;
  int sum;
  SegTreeNode *left, *right;
  SegTreeNode(int start, int end, int sum, SegTreeNode *left = nullptr,
              SegTreeNode *right = nullptr)
      : start(start), end(end), sum(sum), left(left), right(right) {}
};

class NumArray {
public:
  SegTreeNode *root;
  SegTreeNode *buildTree(vector<int> &nums, int start, int end) {
    if (start == end)
      return new SegTreeNode(start, end, nums[start]);

    int mid = (start + end) / 2;
    SegTreeNode *left = buildTree(nums, start, mid);
    SegTreeNode *right = buildTree(nums, mid + 1, end);

    return new SegTreeNode(start, end, left->sum + right->sum, left, right);
  }

  void updateTree(SegTreeNode *root, int i, int val) {
    if (root->start == i && root->end == i) {
      root->sum = val;
      return;
    }

    int mid = (root->start + root->end) / 2;
    if (i <= mid)
      updateTree(root->left, i, val);
    else
      updateTree(root->right, i, val);
    root->sum = root->left->sum + root->right->sum;
  }

  int queryTree(SegTreeNode *root, int i, int j) {
    if (root->start == i && root->end == j)
      return root->sum;
    int mid = (root->start + root->end) / 2;
    if (j <= mid)
      return queryTree(root->left, i, j);
    else if (i > mid)
      return queryTree(root->right, i, j);
    return queryTree(root->left, i, mid) + queryTree(root->right, mid + 1, j);
  }

  NumArray(vector<int> &nums) { root = buildTree(nums, 0, nums.size() - 1); }

  void update(int index, int val) { updateTree(root, index, val); }

  int sumRange(int left, int right) { return queryTree(root, left, right); }
};