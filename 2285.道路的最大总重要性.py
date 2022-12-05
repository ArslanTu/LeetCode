#
# @lc app=leetcode.cn id=2285 lang=python3
#
# [2285] 道路的最大总重要性
#
from typing import List
# @lc code=start
class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        cities = [0] * n
        for road in roads:
            cities[road[0]] += 1
            cities[road[1]] += 1
        cities.sort()
        return sum(city * i for city, i in enumerate(cities, 1))
# @lc code=end

