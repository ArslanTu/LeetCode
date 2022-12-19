#
# @lc app=leetcode.cn id=23 lang=python3
#
# [23] 合并K个升序链表
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
from heapq import heappop, heappush
from typing import List, Optional


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        ans = []
        n = len(lists)
        for i in range(n):
            cur = lists[i]
            while cur != None:
                heappush(ans, cur.val)
                cur = cur.next
        dummy = ListNode()
        cur = dummy
        while ans != []:
            cur.next = ListNode(heappop(ans))
            cur = cur.next
        return dummy.next
# @lc code=end

