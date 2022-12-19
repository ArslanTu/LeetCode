#
# @lc app=leetcode.cn id=2233 lang=python3
#
# [2233] K 次增加后的最大乘积
#

# @lc code=start
from heapq import heapify, heapreplace
from typing import List


class Solution:
    def maximumProduct(self, nums: List[int], k: int) -> int:
        MOD = 1000000007
        heapify(nums)
        while k > 0:
            heapreplace(nums, nums[0] + 1)
            k -= 1
        ans = 1
        for num in nums:
            ans = (ans * num) % MOD
        return ans
# @lc code=end

