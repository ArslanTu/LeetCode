#
# @lc app=leetcode.cn id=2200 lang=python3
#
# [2200] 找出数组中的所有 K 近邻下标
#

# @lc code=start
from typing import List


class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        ans = set()
        n = len(nums)
        for i in range(n):
            if nums[i] == key:
                for j in range(1, k + 1):
                    ans.add(i)
                    if 0 <= i - j < n: ans.add(i - j)
                    if 0 <= i + j < n: ans.add(i + j)
        ans = sorted(list(ans))
        return ans
# @lc code=end

