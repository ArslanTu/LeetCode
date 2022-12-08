#
# @lc app=leetcode.cn id=2262 lang=python3
#
# [2262] 字符串的总引力
#

# @lc code=start
class Solution:
    def appealSum(self, s: str) -> int:
        ans = 0
        n = len(s)
        for i in range(n):
            cnt = [0] * 26
            for j in range(i, n):
                cnt[ord(s[j]) - 97] = 1
                ans += sum(cnt)
        return ans
# @lc code=end

