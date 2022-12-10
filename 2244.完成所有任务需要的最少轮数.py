#
# @lc app=leetcode.cn id=2244 lang=python3
#
# [2244] 完成所有任务需要的最少轮数
#

# @lc code=start
from typing import List


class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        dic = {}
        ans = 0
        for task in tasks:
            if task not in dic: dic[task] = 1
            else: dic[task] += 1
        for cnt in dic.values():
            if cnt == 1: return -1
            ans += int(cnt / 3)
            if cnt % 3 != 0: ans += 1
        return ans
# @lc code=end

