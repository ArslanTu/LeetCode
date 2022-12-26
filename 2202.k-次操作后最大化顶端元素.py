#
# @lc app=leetcode.cn id=2202 lang=python3
#
# [2202] K 次操作后最大化顶端元素
#

# @lc code=start
from typing import List


class Solution:
    def maximumTop(self, nums: List[int], k: int) -> int:
        n = len(nums)
        origin_k = k
        if n == 1 and (k & 1) == 1: return -1
        k = k if k <= n - 1 else n - 1
        nums = sorted(zip(nums[:k + 1:], range(k + 1)), reverse = True)
        if nums[0][1] == origin_k - 1: return nums[1][0]
        else: return nums[0][0]
# @lc code=end

