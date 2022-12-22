#
# @lc app=leetcode.cn id=373 lang=python3
#
# [373] 查找和最小的 K 对数字
#

# @lc code=start
from cmath import inf
from heapq import heappop, heappush, nsmallest
from typing import List


class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        hp = []
        n1 = len(nums1)
        n2 = len(nums2)
        k = k if k <= n1 * n2 else n1 * n2
        ans = []
        for index in range(n1):
            heappush(hp, [nums1[index] + nums2[0], index, 0])
        for i in range(k):
            _, index_1, index_2 = heappop(hp)
            ans.append([nums1[index_1], nums2[index_2]])
            if index_2 < n2 - 1:
                heappush(hp, [nums1[index_1] + nums2[index_2 + 1], index_1, index_2 + 1])
        return ans
# @lc code=end

