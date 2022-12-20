#
# @lc app=leetcode.cn id=659 lang=python3
#
# [659] 分割数组为连续子序列
#

# @lc code=start
from collections import defaultdict
from heapq import heappop, heappush, heapreplace
from typing import List


class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        dic = defaultdict(list)
        for num in nums:
            if dic[num - 1]:
                len = heappop(dic[num - 1])
                heappush(dic[num], len + 1)
            else: heappush(dic[num], 1)
        keys = dic.keys()
        for key in keys:
            if dic[key] and dic[key][0] < 3: return False
        return True
# @lc code=end

