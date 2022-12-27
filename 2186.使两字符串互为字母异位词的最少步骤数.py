#
# @lc app=leetcode.cn id=2186 lang=python3
#
# [2186] 使两字符串互为字母异位词的最少步骤数
#

# @lc code=start
class Solution:
    def minSteps(self, s: str, t: str) -> int:
        return sum(abs(s.count(chr(97 + i)) - t.count(chr(97 + i))) for i in range(26))
# @lc code=end