#
# @lc app=leetcode.cn id=378 lang=python3
#
# [378] 有序矩阵中第 K 小的元素
#

# @lc code=start
from heapq import heappop, heappush, nlargest
from typing import List


class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        hp = []
        n = len(matrix)
        for i in range(n):
            for j in range(n):
                heappush(hp, -matrix[i][j])
                if len(hp) > k:
                    heappop(hp)
        return -hp[0]
# @lc code=end

