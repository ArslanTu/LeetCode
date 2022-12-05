#
# @lc app=leetcode.cn id=2279 lang=python3
#
# [2279] 装满石头的背包的最大数量
#
from typing import List
# @lc code=start
class Solution:
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
        n = len(capacity)
        for i in range(n): capacity[i] -= rocks[i]
        capacity.sort()
        for i in range(n):
            additionalRocks -= capacity[i]
            if additionalRocks < 0: return i
        return n
# @lc code=end

