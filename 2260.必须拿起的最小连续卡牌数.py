#
# @lc app=leetcode.cn id=2260 lang=python3
#
# [2260] 必须拿起的最小连续卡牌数
#

# @lc code=start
from cmath import inf
from typing import List


class Solution:
    def minimumCardPickup(self, cards: List[int]) -> int:
        last = {}
        n = len(cards)
        ans = inf
        for i in range(n):
            if cards[i] not in last: last[cards[i]] = i
            else: 
                ans = min(ans, i - last[cards[i]] + 1)
                last[cards[i]] = i
        if ans == inf: return -1
        else: return ans
# @lc code=end

