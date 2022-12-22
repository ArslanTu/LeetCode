#
# @lc app=leetcode.cn id=2215 lang=python3
#
# [2215] 找出两数组的不同
#

# @lc code=start
from typing import List


class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        ans = [[], []]
        rec_1, rec_2 = set(nums1), set(nums2)
        for num in rec_1:
            if num not in rec_2: ans[0].append(num)
        for num in rec_2:
            if num not in rec_1: ans[1].append(num)
        return ans
# @lc code=end

