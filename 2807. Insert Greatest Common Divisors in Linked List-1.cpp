class Solution {
public:
  ListNode *insertGreatestCommonDivisors(ListNode *head) {
    if (!head)
      return nullptr;

    ListNode *cur = head;
    while (cur && cur->next) {
      ListNode *nxt = cur->next;
      ListNode *newNode = new ListNode(gcd(cur->val, cur->next->val));
      cur->next = newNode;
      newNode->next = nxt;
      cur = nxt;
    }

    return head;
  }
};