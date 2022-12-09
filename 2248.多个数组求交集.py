#
# @lc app=leetcode.cn id=2248 lang=python3
#
# [2248] 多个数组求交集
#

# @lc code=start
from typing import List


class Solution:
    def intersection(self, nums: List[List[int]]) -> List[int]:
        cnt = [0] * 1001
        for num in nums:
            for number in num:
                cnt[number] += 1
        ans = []
        n = len(nums)
        for i in range(1001): 
            if cnt[i] == n: ans.append(i)
        return ans
# @lc code=end

