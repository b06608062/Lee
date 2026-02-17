/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head)
      return nullptr;
    int n = 0;
    ListNode *cur = head;
    while (cur) {
      n++;
      cur = cur->next;
    }

    k %= n;
    if (k == 0)
      return head;

    k = n - k;
    ListNode *prev = nullptr;
    cur = head;
    while (k--) {
      prev = cur;
      cur = cur->next;
    }

    ListNode *ret = cur;
    prev->next = nullptr;
    while (cur->next) {
      cur = cur->next;
    }
    cur->next = head;

    return ret;
  }
};