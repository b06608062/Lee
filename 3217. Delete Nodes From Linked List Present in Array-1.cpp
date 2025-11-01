class Solution {
public:
  ListNode *modifiedList(vector<int> &nums, ListNode *head) {
    unordered_set<int> uset;
    for (auto x : nums)
      uset.insert(x);

    ListNode dummy;
    ListNode *cur = &dummy, *ptr = head;

    while (ptr) {
      if (!uset.count(ptr->val)) {
        cur->next = ptr;
        cur = cur->next;
      }
      ptr = ptr->next;
    }
    cur->next = nullptr;

    return dummy.next;
  }
};