#
# @lc app=leetcode.cn id=2251 lang=python3
#
# [2251] 花期内花的数目
#

# @lc code=start
from collections import defaultdict
from typing import List


class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], persons: List[int]) -> List[int]:
        # 用字典存储差分数组
        diff = defaultdict(int)
        for interval in flowers:
            diff[interval[0]] += 1
            diff[interval[1] + 1] -= 1
        # 获取排序后的时间节点
        times = sorted(diff.keys())
        i = sum = 0
        n = len(persons)
        ans = [0 for i in range(n)]
        # 将persons排序，遍历其值和对应下标，累加其之前的时间节点的差分
        for p, id in sorted(zip(persons, range(n))):
            while i < len(times) and times[i] <= p:
                sum += diff[times[i]]
                i += 1
            ans[id] = sum
        return ans
# @lc code=end

