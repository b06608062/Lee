# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        prev = None
        cur = slow
        while cur is not None:
            nxt = cur.next
            cur.next = prev
            prev = cur
            cur = nxt

        head1 = head
        head2 = prev
        while head2.next is not None:
            nxt1 = head1.next
            nxt2 = head2.next
            head1.next = head2
            head2.next = nxt1
            head1 = nxt1
            head2 = nxt2
