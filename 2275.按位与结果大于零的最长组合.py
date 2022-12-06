#
# @lc app=leetcode.cn id=2275 lang=python3
#
# [2275] 按位与结果大于零的最长组合
#
from typing import List
# @lc code=start
class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        num = [0] * 24
        for ca in candidates:
            pos = 0
            while ca != 0:
                if (ca & 1) == 1: num[pos] += 1
                ca >>= 1
                pos += 1
        return max(num)
# @lc code=end