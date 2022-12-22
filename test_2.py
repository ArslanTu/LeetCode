from heapq import heappop, heappush
from typing import List


class Solution:
    def maxValueOfCoins(self, piles: List[List[int]], k: int) -> int:
        hp = []
        m = len(piles)
        last = [[0, 0] for i in range(m)]
        for i in range(m):
            n = k if k < len(piles[i]) else len(piles[i])
            sum = 0
            for j in range(n):
                sum += piles[i][j]
                value = sum / (j + 1)
                heappush(hp, [-value, j + 1, i, sum]) # 每单位价值，操作数，所属栈，总价值
        ans = 0
        while hp and k > 0:
            _, ops, index, sum = heappop(hp)
            if k + last[index][0] >= ops:
                k += last[index][0]
                ans -= last[index][1]
                
                k -= ops
                ans += sum
                last[index] = [ops, sum]
        return ans
    
piles = [[37,88],[51,64,65,20,95,30,26],[9,62,20],[44]]
solution = Solution()
solution.maxValueOfCoins(piles, 9)