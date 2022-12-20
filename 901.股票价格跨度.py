#
# @lc app=leetcode.cn id=901 lang=python3
#
# [901] 股票价格跨度
#

# @lc code=start
from inspect import stack
from typing import List


class StockSpanner:
    __stack: List[List[int]]
    def __init__(self):
        self.__stack = []

    def next(self, price: int) -> int:
        res = 1
        while self.__stack and self.__stack[-1][1] <= price:
            res += self.__stack.pop()[0]
        self.__stack.append([res, price])
        return res
# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
# @lc code=end

