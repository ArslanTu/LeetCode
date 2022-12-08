#
# @lc app=leetcode.cn id=2255 lang=python3
#
# [2255] 统计是给定字符串前缀的字符串数目
#

# @lc code=start
from typing import List


class Solution:
    def countPrefixes(self, words: List[str], s: str) -> int:
        preSet = set()
        for i in range(len(s)):
            preSet.add(s[0:i + 1])
        ans = 0
        for word in words:
            if word in preSet: ans += 1
        return ans
# @lc code=end

