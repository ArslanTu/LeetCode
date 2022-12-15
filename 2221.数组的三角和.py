#
# @lc app=leetcode.cn id=2221 lang=python3
#
# [2221] 数组的三角和
#

# @lc code=start
from typing import List


class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        while len(nums) > 1:
            newNums = [0 for i in range(len(nums) - 1)]
            for i in range(len(newNums)):
                newNums[i] = (nums[i] + nums[i + 1]) %10
            nums = newNums
        return nums[0]
# @lc code=end

