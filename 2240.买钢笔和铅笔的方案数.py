#
# @lc app=leetcode.cn id=2240 lang=python3
#
# [2240] 买钢笔和铅笔的方案数
#

# @lc code=start
class Solution:
    def waysToBuyPensPencils(self, total: int, cost1: int, cost2: int) -> int:
        cost = [cost1, cost2]
        dp = [1 for i in range(total + 1)]
        for i in range(2):
            for j in range(total + 1):
                if j >= cost[i]: dp[j] += dp[j - cost[i]]
        return dp[total]
# @lc code=end

