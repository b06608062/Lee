// Follow up: Could you do it in O(n) time and O(1) space?
class Solution {
public:
  bool isPalindrome(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    if (fast) {
      slow = slow->next;
    }

    ListNode *prev = nullptr, *cur = slow;
    while (cur) {
      ListNode *nxt = cur->next;
      cur->next = prev;
      prev = cur;
      cur = nxt;
    }

    ListNode *p1 = head, *p2 = prev;
    while (p2) {
      if (p1->val != p2->val)
        return false;
      p1 = p1->next;
      p2 = p2->next;
    }

    return true;
  }
};