# class Solution:
#     def countTexts(self, pressedKeys: str) -> int:
#         ans = 0
#         MOD = 1000000007
#         n = len(pressedKeys)
#         dp = [0] * (n + 1)
#         dp[0] = dp[1] = 1
#         for i in range(2, n + 1):
#             j = i - 1
#             while j >= 0 and i - j <= 3:
#                 dp[i] = (dp[i] + dp[j]) % MOD
#                 j -= 1
#         ans = dp[n]
#         return ans

class Solution:
    def countTexts(self, pressedKeys: str) -> int:
        nums = [0, 0, 3, 3, 3, 3, 3, 4, 3, 4]
        n = len(pressedKeys)
        ans = 1
        MOD = 1000000007
        start = 0
        keys = []
        for i in range(n + 1):
            if i == n or pressedKeys[i] != pressedKeys[start]:
                keys.append(pressedKeys[start:i])
                start = i
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

solution = Solution()
solution.countTexts("222222222222222222222222222222222222")