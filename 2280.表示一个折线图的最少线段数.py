#
# @lc app=leetcode.cn id=2280 lang=python3
#
# [2280] 表示一个折线图的最少线段数
#
from typing import List
# @lc code=start
class Solution:
    def minimumLines(self, stockPrices: List[List[int]]) -> int:
        n = len(stockPrices)
        if n == 1: return 0
        if n == 2: return 1
        stockPrices.sort(key = lambda x: x[0])
        # pre = (stockPrices[1][1] - stockPrices[0][1]) / (stockPrices[1][0] - stockPrices[0][0])
        # ans = 1
        # for i in range(1, len(stockPrices)):
        #     cur = (stockPrices[i][1] - stockPrices[i - 1][1]) / (stockPrices[i][0] - stockPrices[i - 1][0])
        #     if  cur != pre:
        #         ans += 1
        #         pre = cur
        # return ans
        ans = 1
        for i in range(2, n):
            if (stockPrices[i - 1][1] - stockPrices[i - 2][1]) * (stockPrices[i][0] - stockPrices[i - 1][0]) != (stockPrices[i][1] - stockPrices[i - 1][1]) * (stockPrices[i - 1][0] - stockPrices[i - 2][0]):
                ans += 1
        return ans
# @lc code=end

