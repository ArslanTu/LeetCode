#
# @lc app=leetcode.cn id=347 lang=python3
#
# [347] 前 K 个高频元素
#

# @lc code=start
from collections import defaultdict
from heapq import heapify, nlargest
from typing import List


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        dic = defaultdict(int)
        for num in nums: dic[num] += 1
        nums = dic.keys()
        freq = []
        for num in nums: freq.append([dic[num], num])
        heapify(freq)
        res = nlargest(k, freq)
        ans = []
        for elem in res: ans.append(elem[1])
        return ans
# @lc code=end

