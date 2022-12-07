#
# @lc app=leetcode.cn id=2266 lang=python3
#
# [2266] 统计打字方案数
#

# @lc code=start
class Solution:
    def countTexts(self, pressedKeys: str) -> int:
        nums = [0, 0, 3, 3, 3, 3, 3, 4, 3, 4]
        n = len(pressedKeys)
        ans = 1
        MOD = 1000000007
        # 分割子串
        start = 0
        keys = []
        for i in range(n + 1):
            if i == n or pressedKeys[i] != pressedKeys[start]:
                keys.append(pressedKeys[start:i])
                start = i
        # 分别处理每个子串
        for key in keys:
            m = len(key)
            dp = [0] * (m + 1)
            dp[0] = dp[1] = 1
            for i in range(2, m + 1):
                j = i - 1
                while j >= 0 and i - j <= nums[int(key[0])]:
                    dp[i] = (dp[i] + dp[j]) % MOD
                    j -= 1
            ans = (ans * dp[m]) % MOD
        return ans
# @lc code=end

