#
# @lc app=leetcode.cn id=2207 lang=python3
#
# [2207] 字符串中最多数目的子字符串
#

# @lc code=start
class Solution:
    def maximumSubsequenceCount(self, text: str, pattern: str) -> int:
        cnts = [0, 0]
        pre1 = []
        for ch in text:
            if ch == pattern[0]:
                cnts[0] += 1
            elif ch == pattern[1]:
                cnts[1] += 1
                pre1.append(cnts[0])
        if pattern[0] == pattern[1]:
            return ((cnts[0] + 1) * cnts[0] // 2)
        if cnts[0] < cnts[1]:
            return sum(pre1) + cnts[1]
        else:
            return sum(pre1) + cnts[0]
# @lc code=end

