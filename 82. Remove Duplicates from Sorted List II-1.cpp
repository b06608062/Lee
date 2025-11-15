class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode dummy;
    dummy.next = head;
    ListNode *cur = &dummy;
    while (cur->next && cur->next->next) {
      int val = cur->next->val;
      if (cur->next->next->val == val)
        while (cur->next && cur->next->val == val)
          cur->next = cur->next->next;
      else
        cur = cur->next;
    }

    return dummy.next;
  }
};