// bubble sort
class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
      bool flag = false;
      for (int j = 0; j < n - 1 - i; ++j)
        if (nums[j] > nums[j + 1]) {
          flag = true;
          swap(nums[j], nums[j + 1]);
        }
      if (!flag)
        break;
    }
    return nums;
  }
};

struct Node {
  int val;
  Node *nxt;
  Node(int val) : val(val), nxt(nullptr) {}
};

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();
    Node dummy(-1);
    Node *cur = &dummy;
    for (auto x : nums) {
      cur->nxt = new Node(x);
      cur = cur->nxt;
    }

    for (int i = 0; i < n - 1; ++i) {
      bool flag = false;
      cur = &dummy;
      for (int j = 0; j < n - 1 - i; ++j) {
        Node *p1 = cur->nxt, *p2 = cur->nxt->nxt;
        if (p1->val > p2->val) {
          flag = true;
          cur->nxt = p2;
          p1->nxt = p2->nxt;
          p2->nxt = p1;
        }
        cur = cur->nxt;
      }
      if (!flag)
        break;
    }

    cur = dummy.nxt;
    for (int i = 0; i < n; ++i) {
      nums[i] = cur->val;
      cur = cur->nxt;
    }
    return nums;
  }
};