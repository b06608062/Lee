class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head)
      return head;

    ListNode *cur = head;
    while (cur->next) {
      if (cur->next->val == cur->val)
        cur->next = cur->next->next;
      else
        cur = cur->next;
    }

    return head;
  }
};