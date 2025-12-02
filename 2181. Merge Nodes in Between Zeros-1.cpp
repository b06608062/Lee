class Solution {
public:
  ListNode *mergeNodes(ListNode *head) {
    ListNode dummy(-1);
    ListNode *ptr = &dummy, *cur = head;
    while (cur) {
      cur = cur->next;
      if (!cur)
        break;
      int sum = 0;
      while (cur->val != 0) {
        sum += cur->val;
        cur = cur->next;
      }

      ptr->next = new ListNode(sum);
      ptr = ptr->next;
    }

    return dummy.next;
  }
};