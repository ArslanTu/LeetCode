#
# @lc app=leetcode.cn id=2209 lang=python3
#
# [2209] 用地毯覆盖后的最少白色砖块
#

# @lc code=start
class Solution:
    def minimumWhiteTiles(self, floor: str, numCarpets: int, carpetLen: int) -> int:
        n = len(floor)
        if numCarpets * carpetLen >= n: return 0
        dp = [[0 for i in range(n)] for j in range(numCarpets + 1)]
        cnt = 0
        for i in range(n):
            if floor[i] == "1":
                cnt += 1
            dp[0][i] = cnt
        for i in range(1, numCarpets + 1):
            for j in range(carpetLen * i, n):
                dp[i][j] = min(dp[i][j - 1] + int(floor[j]), dp[i - 1][j - carpetLen])
        return dp[numCarpets][n - 1]
# @lc code=end

