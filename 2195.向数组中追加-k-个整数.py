#
# @lc app=leetcode.cn id=2195 lang=python3
#
# [2195] 向数组中追加 K 个整数
#

# @lc code=start
from typing import List


class Solution:
    def minimalKSum(self, nums: List[int], k: int) -> int:
        ans = 0
        nums.append(0)
        nums.sort()
        nums.append(int(1e+9 + 1))
        n = len(nums)
        for i in range(1, n):
            if k == 0: break
            if nums[i - 1] + 1 <= min(nums[i - 1] + k, nums[i] - 1):
                ans += (nums[i - 1] + 1 + min(nums[i - 1] + k, nums[i] - 1)) * (min(nums[i - 1] + k, nums[i] - 1) - (nums[i - 1])) // 2
                k -= (min(nums[i - 1] + k, nums[i] - 1) - (nums[i - 1]))
        return ans
# @lc code=end

