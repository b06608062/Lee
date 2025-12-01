class Solution {
public:
  ListNode *sortList(ListNode *head) {
    if (!head || !head->next)
      return head;

    int n = 0;
    ListNode *ptr = head;
    while (ptr) {
      n++;
      ptr = ptr->next;
    }

    ListNode dummy(-1, head);
    for (int step = 1; step < n; step <<= 1) {
      ListNode *prev = &dummy;
      ListNode *cur = dummy.next;
      while (cur) {
        ListNode *left = cur;
        ListNode *right = split(left, step);
        cur = split(right, step);
        prev = merge(left, right, prev);
      }
    }

    return dummy.next;
  }

  ListNode *split(ListNode *head, int step) {
    if (!head)
      return nullptr;
    ListNode *prev = head;
    for (int i = 1; prev && i < step; ++i)
      prev = prev->next;
    if (!prev)
      return nullptr;
    ListNode *next = prev->next;
    prev->next = nullptr;
    return next;
  }

  ListNode *merge(ListNode *l1, ListNode *l2, ListNode *prev) {
    ListNode *cur = prev;

    while (l1 && l2) {
      if (l1->val <= l2->val) {
        cur->next = l1;
        l1 = l1->next;
      } else {
        cur->next = l2;
        l2 = l2->next;
      }
      cur = cur->next;
    }

    cur->next = l1 ? l1 : l2;

    while (cur->next)
      cur = cur->next;

    return cur;
  }
};
