#
# @lc app=leetcode.cn id=2190 lang=python3
#
# [2190] 数组中紧跟 key 之后出现最频繁的数字
#

# @lc code=start
from collections import defaultdict
from typing import List


class Solution:
    def mostFrequent(self, nums: List[int], key: int) -> int:
        dic = defaultdict(int)
        for i in range(len(nums) - 1):
            if nums[i] == key: dic[nums[i + 1]] += 1
        nums = list(dic.keys())
        ans = 0
        maxF = 0
        for num in nums:
            if dic[num] > maxF:
                ans = num
                maxF = dic[num]
        return ans
# @lc code=end

p1 = [2,2,2,2,3]
sl = Solution()
sl.mostFrequent(p1, 2)