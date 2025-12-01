class Solution {
public:
  ListNode *sortList(ListNode *head) {
    if (!head || !head->next)
      return head;
    ListNode *fast = head, *slow = head, *prev = nullptr;
    while (fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    prev->next = nullptr;
    ListNode *l1 = sortList(head);
    ListNode *l2 = sortList(slow);
    return merge(l1, l2);
  }

  ListNode *merge(ListNode *l1, ListNode *l2) {
    ListNode dummy;
    ListNode *cur = &dummy;
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
    return dummy.next;
  }
};