#
# @lc app=leetcode.cn id=373 lang=python3
#
# [373] 查找和最小的 K 对数字
#

# @lc code=start
from heapq import heappush, nsmallest
from typing import List


class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        hp = []
        for i in range(min(k, len(nums1))):
            for j in range(min(k, len(nums2))):
                heappush(hp, [nums1[i] + nums2[j], nums1[i], nums2[j]])
        ans = [[num1, num2] for _, num1, num2 in nsmallest(k, hp)]
        return ans
# @lc code=end

