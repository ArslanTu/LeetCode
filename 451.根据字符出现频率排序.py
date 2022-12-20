#
# @lc app=leetcode.cn id=451 lang=python3
#
# [451] 根据字符出现频率排序
#

# @lc code=start
from heapq import heappop, heappush


class Solution:
    def frequencySort(self, s: str) -> str:
        freq = [0 for i in range(123)]
        hp = []
        for ch in s: freq[ord(ch)] += 1
        for i in range(48, 123):
            if freq[i] != 0:
                heappush(hp, [-freq[i], i])
        s = ""
        while hp:
            num, ch = heappop(hp)
            s += chr(ch) * (-num)
        return s
# @lc code=end

