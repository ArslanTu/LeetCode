#
# @lc app=leetcode.cn id=1014 lang=python3
#
# [1014] 最佳观光组合
#

# @lc code=start
from typing import List


class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        n = len(values)
        dp = [0 for i in range(n)]
        ans = 0
        for i in range(1, n):
            score_1 = values[i] + values[i - 1] - 1
            score_2 = dp[i - 1] + values[i] - values[i - 1] - 1
            dp[i] = score_1 if score_1 > score_2 else score_2
            ans = ans if ans > dp[i] else dp[i]
        return ans
# @lc code=end

