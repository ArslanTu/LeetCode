#
# @lc app=leetcode.cn id=239 lang=python3
#
# [239] 滑动窗口最大值
#

# @lc code=start
from heapq import heapify, heappop, heappush, nlargest
from typing import List


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        # 双端队列
        # n = len(nums)
        # if n == 1: return nums
        # ans = []
        # queue = []
        
        # for i in range(n):
        #     if queue and queue[0] == i - k: queue.pop(0)
        #     while queue and nums[queue[-1]] < nums[i]: queue.pop()
        #     queue.append(i)
        #     if i >= k - 1: ans.append(nums[queue[0]])
        
        # return ans

        # 大根堆
        hp, ans = [], []
        for i, num in enumerate(nums):
            while hp and hp[0][1] <= i - k: heappop(hp)
            heappush(hp, [-num, i])
            if i >= k - 1: ans.append(-hp[0][0])
        return ans
# @lc code=end

