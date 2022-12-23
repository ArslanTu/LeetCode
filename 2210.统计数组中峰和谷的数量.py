#
# @lc app=leetcode.cn id=2210 lang=python3
#
# [2210] 统计数组中峰和谷的数量
#

# @lc code=start
from typing import List


class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        ans = 0
        n = len(nums)
        i = 1
        while i < n and nums[i] == nums[i - 1]: i += 1
        if i >= n - 1: return 0 
        while i < n - 1:
            if (nums[i - 1] - nums[i]) * (nums[i] - nums[i + 1]) < 0:
                ans += 1
            elif (nums[i - 1] - nums[i]) * (nums[i] - nums[i + 1]) == 0:
                left = (nums[i - 1] - nums[i])
                i += 1
                while i < n - 1 and nums[i] == nums[i + 1]:
                    i += 1
                if i < n - 1 and left * (nums[i] - nums[i + 1]) < 0:
                    ans += 1
            i += 1
        return ans
# @lc code=end

