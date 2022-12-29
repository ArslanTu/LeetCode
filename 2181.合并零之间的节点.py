#
# @lc app=leetcode.cn id=2181 lang=python3
#
# [2181] 合并零之间的节点
#

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from typing import Optional


class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        cur = dummy
        while head:
            if head.val == 0 and head.next != None:
                p = ListNode()
                cur.next = p
                cur = cur.next
            else:
                cur.val += head.val
            head = head.next
        return dummy.next
# @lc code=end

