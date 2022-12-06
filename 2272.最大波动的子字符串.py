#
# @lc app=leetcode.cn id=2272 lang=python3
#
# [2272] 最大波动的子字符串
#

# @lc code=start
from itertools import permutations
from math import inf
from string import ascii_lowercase


class Solution:
    def largestVariance(self, s: str) -> int:
        ans = 0
        for a, b in permutations(ascii_lowercase, 2):
            diff, diffWithB = 0, -inf
            for ch in s:
                if ch == a:
                    diff += 1
                    diffWithB += 1
                elif ch == b:
                    diff -= 1
                    diffWithB = diff
                    if diff < 0:
                        diff = 0
                if diffWithB > ans:
                    ans = diffWithB
        return ans
# @lc code=end

