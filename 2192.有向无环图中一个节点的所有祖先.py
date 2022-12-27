#
# @lc app=leetcode.cn id=2192 lang=python3
#
# [2192] 有向无环图中一个节点的所有祖先
#

# @lc code=start
from typing import List, Set


class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        graph = [[] for i in range(n)]
        for e in edges:
            graph[e[1]].append(e[0])
        computed = [0 for i in range(n)]
        fathers = [set() for i in range(n)]
        def dfs(cur: int) -> Set[int]:
            if computed[cur]: return fathers[cur]
            fc = set()
            for v in graph[cur]:
                fc.add(v)
                fc = fc.union(dfs(v))
            computed[cur] = 1
            fathers[cur] = fc
            return fc
        for i in range(n):
            dfs(i)
        return [sorted(list(fathers[i])) for i in range(n)]
# @lc code=end

