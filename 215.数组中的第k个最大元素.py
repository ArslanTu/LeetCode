#
# @lc app=leetcode.cn id=215 lang=python3
#
# [215] 数组中的第K个最大元素
#

# @lc code=start
from heapq import heapify, nlargest
from typing import List


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heapify(nums)
        return nlargest(k, nums)[k - 1]
# @lc code=end

