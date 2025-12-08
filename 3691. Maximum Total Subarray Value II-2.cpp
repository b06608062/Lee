// mark
// 2469
// Segment Tree Node + 最大值最小值區間查詢 + 最大值-最小值貪心取前 k 大
struct Element {
  int val, i, j;
};

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

  void updateTree(SegTreeNode *root, int i, int val) {
    if (root->start == i && root->end == i) {
      root->minVal = root->maxVal = val;
      return;
    }

    int mid = (root->start + root->end) / 2;
    if (i <= mid)
      updateTree(root->left, i, val);
    else
      updateTree(root->right, i, val);

    root->minVal = min(root->left->minVal, root->right->minVal);
    root->maxVal = max(root->left->maxVal, root->right->maxVal);
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

  long long maxTotalValue(vector<int> &nums, int k) {
    int n = nums.size();

    root = buildTree(nums, 0, n - 1);

    set<pair<int, int>> sset;
    auto comp = [](auto &a, auto &b) { return a.val < b.val; };
    priority_queue<Element, vector<Element>, decltype(comp)> pq(comp);

    auto all = queryTree(root, 0, n - 1);
    sset.insert({0, n - 1});
    pq.push({all.second - all.first, 0, n - 1});
    long long res = 0;

    while (!pq.empty() && k > 0) {
      auto [val, i, j] = pq.top();
      pq.pop();
      res += val;
      k--;
      if (i < j) {
        if (!sset.count({i + 1, j})) {
          auto q = queryTree(root, i + 1, j);
          sset.insert({i + 1, j});
          pq.push({q.second - q.first, i + 1, j});
        }
        if (!sset.count({i, j - 1})) {
          auto q = queryTree(root, i, j - 1);
          sset.insert({i, j - 1});
          pq.push({q.second - q.first, i, j - 1});
        }
      }
    }

    return res;
  }
};