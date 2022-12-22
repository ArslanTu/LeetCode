#
# @lc app=leetcode.cn id=2216 lang=python3
#
# [2216] 美化数组的最少删除数
#

# @lc code=start
from typing import List


class Solution:
    def minDeletion(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        i = 0
        while i < n:
            if i == n - 1:
                ans += 1 
                i += 1
            else:
                if nums[i] == nums[i + 1]:
                    start = i + 1
                    end = i + 2
                    while start < n and nums[start] == nums[i]:
                        end += 1
                        start += 1
                        ans += 1
                    i = end
                    if start == n:
                        ans += 1
                else: i += 2
        return ans
# @lc code=end

