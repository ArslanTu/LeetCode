#
# @lc app=leetcode.cn id=2218 lang=python3
#
# [2218] 从栈中取出 K 个硬币的最大面值和
#

# @lc code=start
from heapq import heappop, heappush
from typing import List


class Solution:
    def maxValueOfCoins(self, piles: List[List[int]], k: int) -> int:
        hp = []
        m = len(piles)
        last = [[0, 0, i] for i in range(m)]
        for i in range(m):
            n = k if k < len(piles[i]) else len(piles[i])
            sum = 0
            for j in range(n):
                sum += piles[i][j]
                value = sum / (j + 1)
                heappush(hp, [-value, j + 1, i]) # 每单位价值，操作数，所属栈
        ans = 0
        while hp and k > 0:
            negValue, ops, index = heappop(hp)
            if k + last[index][1] >= ops:
                k += last[index][1]
                ans -= int(last[index][0] * last[index][1])
                
                k -= ops
                ans += int((-negValue) * ops)
                last[index] = [-negValue, ops]
        return ans
# @lc code=end

