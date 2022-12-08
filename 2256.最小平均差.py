#
# @lc app=leetcode.cn id=2256 lang=python3
#
# [2256] 最小平均差
#

# @lc code=start
from cmath import inf
from typing import List


class Solution:
    def minimumAverageDifference(self, nums: List[int]) -> int:
        n = len(nums)
        preSum = 0
        afterSum = sum(nums)
        ans = -1
        minDiff = inf
        for i in range(n):
            preSum += nums[i]
            afterSum -= nums[i]
            if i < n - 1: cur = abs(int(preSum / (i + 1)) - int(afterSum / (n - i - 1)))
            else: cur = preSum / (i + 1)
            if cur < minDiff: 
                ans = i
                minDiff = cur
        return ans
# @lc code=end

