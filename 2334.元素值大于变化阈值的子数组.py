#
# @lc app=leetcode.cn id=2334 lang=python3
#
# [2334] 元素值大于变化阈值的子数组
#

# @lc code=start
from math import ceil
from typing import List


class Solution:
    def validSubarraySize(self, nums: List[int], threshold: int) -> int:
        n = len(nums)
        fa = list(range(n + 1))
        size = [0 for i in range(n + 1)]
        def root(x: int) -> int:
            if fa[x] == x: return x
            else: return root(fa[x])
        for num, i in sorted(zip(nums, range(n)), reverse=True):
            j = root(i + 1)
            fa[i] = j
            size[j] += size[i] + 1
            if num > threshold // size[j]: return size[j]
        return -1
# @lc code=end

