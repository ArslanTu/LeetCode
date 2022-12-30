#
# @lc app=leetcode.cn id=207 lang=python3
#
# [207] 课程表
#

# @lc code=start
from typing import List


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = [[] for i in range(numCourses)]
        inNum = [0 for i in range(numCourses)]
        for v1, v2 in prerequisites:
            graph[v2].append(v1)
            inNum[v1] += 1
        queue = []
        for i in range(numCourses):
            if not inNum[i]:
                queue.append(i)
        while queue:
            cur = queue.pop(0)
            numCourses -= 1
            for v in graph[cur]:
                inNum[v] -= 1
                if not inNum[v]:
                    queue.append(v)
        return not numCourses
# @lc code=end

sl = Solution()
p1 = 2
p2 = [[1,0]]
print(sl.canFinish(p1, p2))

def topology(graph: List[List[int]]) -> bool:
    n = len(graph)
    inNum = [0 for i in range(n)]
    queue = []
    for v in range(n):
        for u in graph[v]:
            inNum[u] += 1
    for v in range(n):
        if not inNum[v]:
            queue.append(v)
    while queue:
        cur = queue.pop(0)
        n -= 1
        for v in graph[cur]:
            inNum[v] -= 1
            if not inNum[v]:
                queue.append(v)
    return not n