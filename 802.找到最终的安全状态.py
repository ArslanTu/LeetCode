#
# @lc app=leetcode.cn id=802 lang=python3
#
# [802] 找到最终的安全状态
#

# @lc code=start
from heapq import heappop, heappush
from typing import List, Set


class Solution:
    def dfs(self, graph: List[List[int]], visited: List[int], cur: int, safePoint: Set[int]) -> bool:
        if len(graph[cur]) == 0:
            safePoint.add(cur)
            return True
        elif cur in safePoint:
            return True
        else:
            for next in graph[cur]:
                if visited[next] == 0:
                    visited[next] = 1
                    flag = self.dfs(graph, visited, next, safePoint)
                    visited[next] = 0
                    if not flag: return False
                    else: safePoint.add(next)
                else: return False
            return True
            
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        safePoint = set()
        n = len(graph)
        visited = [0 for i in range(n)]
        for v in range(n):
            if v not in safePoint:
                visited[v] = 1
                if self.dfs(graph, visited, v, safePoint):
                    safePoint.add(v)
                visited[v] = 0
        ans = sorted(list(safePoint))
        return ans
# @lc code=end

