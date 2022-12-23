#
# @lc app=leetcode.cn id=2212 lang=python3
#
# [2212] 射箭比赛中的最大得分
#

# @lc code=start
from typing import List


class Solution:
    __res: List[int]
    __maxProfit: int
    def count(self, rest: int, profit: int, ans: List[int], cur: int, aliceArrows: List[int]) -> None:
        if cur >= 12: return
        if rest >= aliceArrows[cur] + 1:
            rest -= aliceArrows[cur] + 1
            ans[cur] = aliceArrows[cur] + 1
            profit += cur
            if profit > self.__maxProfit:
                self.__maxProfit = profit
                temp = list(ans)
                temp[0] += rest
                self.__res = list(temp)
            self.count(rest, profit, ans, cur + 1, aliceArrows)
            rest += aliceArrows[cur] + 1
            ans[cur] = 0
            profit -= cur
        self.count(rest, profit, ans, cur + 1, aliceArrows)
    def maximumBobPoints(self, numArrows: int, aliceArrows: List[int]) -> List[int]:
        self.__res = [0 for i in range(12)]
        self.__maxProfit = 0
        profit = 0
        ans = [0 for i in range(12)]
        cur = 0
        self.count(numArrows, profit, ans, cur, aliceArrows)
        return self.__res
# @lc code=end

