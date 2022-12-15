#
# @lc app=leetcode.cn id=2220 lang=python3
#
# [2220] 转换数字的最少位翻转次数
#

# @lc code=start
class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        start ^= goal
        return start.bit_count()
# @lc code=end

