// Segment Tree + Binary Search
struct SegTreeNode {
  int start, end;
  int minVal, maxVal;
  SegTreeNode *left, *right;
  SegTreeNode(int start, int end, int minVal, int maxVal,
              SegTreeNode *left = nullptr, SegTreeNode *right = nullptr)
      : start(start), end(end), minVal(minVal), maxVal(maxVal), left(left),
        right(right) {}
};

class Solution {
public:
  SegTreeNode *root;
  SegTreeNode *buildTree(vector<int> &nums, int start, int end) {
    if (start == end)
      return new SegTreeNode(start, end, nums[start], nums[start]);

    int mid = (start + end) / 2;
    SegTreeNode *left = buildTree(nums, start, mid);
    SegTreeNode *right = buildTree(nums, mid + 1, end);
    return new SegTreeNode(start, end, min(left->minVal, right->minVal),
                           max(left->maxVal, right->maxVal), left, right);
  }

  pair<int, int> queryTree(SegTreeNode *root, int i, int j) {
    if (root->start == i && root->end == j)
      return {root->minVal, root->maxVal};

    int mid = (root->start + root->end) / 2;
    if (j <= mid)
      return queryTree(root->left, i, j);
    else if (i > mid)
      return queryTree(root->right, i, j);

    auto pLeft = queryTree(root->left, i, mid);
    auto pRight = queryTree(root->right, mid + 1, j);

    return {min(pLeft.first, pRight.first), max(pLeft.second, pRight.second)};
  }

  int longestSubarray(vector<int> &nums, int limit) {
    int n = nums.size();

    root = buildTree(nums, 0, n - 1);

    auto helper = [&](int len) {
      for (int i = 0; i + len - 1 < n; ++i) {
        auto [minVal, maxVal] = queryTree(root, i, i + len - 1);
        if (maxVal - minVal <= limit)
          return true;
      }
      return false;
    };

    int l = 2, r = n + 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (helper(m))
        l = m + 1;
      else
        r = m;
    }

    return l - 1;
  }
};