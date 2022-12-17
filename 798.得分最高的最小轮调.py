#
# @lc app=leetcode.cn id=798 lang=python3
#
# [798] 得分最高的最小轮调
#

# @lc code=start
from typing import List


class Solution:
    def bestRotation(self, nums: List[int]) -> int:
        n = len(nums)
        points = [0 for i in range(n)]
        for i in range(n):
            points[(i + 1) % n] += 1
            points[(n + i - nums[i] + 1) % n] -= 1
        maxScore = points[0]
        k = 0
        for i in range(1, n):
            points[i] += points[i - 1]
            if points[i] > maxScore:
                maxScore = points[i]
                k = i
        return k
# @lc code=end

