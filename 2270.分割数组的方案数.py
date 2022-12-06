#
# @lc app=leetcode.cn id=2270 lang=python3
#
# [2270] 分割数组的方案数
#
from typing import List
# @lc code=start
class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        total = sum(nums)
        n = len(nums)
        ans = 0
        cur = 0
        for i in range(n - 1):
            cur += nums[i]
            total -= nums[i]
            if (cur >= total): ans += 1
        return ans
# @lc code=end

