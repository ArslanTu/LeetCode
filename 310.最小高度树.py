#
# @lc app=leetcode.cn id=310 lang=python3
#
# [310] 最小高度树
#

# @lc code=start
from typing import List


class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1: return [0]
        graph = [[] for _ in range(n)]
        for v1, v2 in edges:
            graph[v1].append(v2)
            graph[v2].append(v1)
        parents = [0 for _ in range(n)]
        def bfs(start: int) -> int:
            visited = [0 for _ in range(n)]
            queue = [start]
            while queue:
                cur = queue.pop(0)
                visited[cur] = 1
                for v in graph[cur]:
                    if not visited[v]:
                        queue.append(v)
                        parents[v] = cur
            return cur
        x = bfs(0)
        y = bfs(x)
        parents[x] = -1
        path = []
        while y != -1:
            path.append(y)
            y = parents[y]
        m = len(path)
        return [path[m >> 1]] if m % 2 else [path[m >> 1], path[(m >> 1) - 1]]
# @lc code=end

