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
  bool isPalindrome(ListNode *head) {
    ListNode *cur = head;
    int n = 0;
    while (cur) {
      n++;
      cur = cur->next;
    }

    stack<int> st;
    cur = head;
    for (int i = 0; i < n / 2; ++i) {
      st.push(cur->val);
      cur = cur->next;
    }

    if (n % 2)
      cur = cur->next;

    while (cur) {
      if (cur->val != st.top())
        return false;
      st.pop();
      cur = cur->next;
    }

    return true;
  }
};