#
# @lc app=leetcode.cn id=547 lang=python3
#
# [547] 省份数量
#

# @lc code=start
from typing import List

# class UF:
#     __fa = []
#     __size = []
#     __count = 0
#     def __init__(self, n: int) -> None:
#         self.__fa = list(range(n))
#         self.__size = [1 for i in range(n)]
#         self.__count = n
#     def find(self, x: int) -> int:
#         if self.__fa[x] != x: self.__fa[x] = self.find(self.__fa[x])
#         return self.__fa[x]
#     def union(self, x: int, y: int) -> None:
#         rootX = self.find(x)
#         rootY = self.find(y)
#         if rootX == rootY: return
#         if self.__size[rootX] <= self.__size[rootY]:
#             self.__fa[rootX] = rootY
#             self.__size[rootY] += self.__size[rootX]
#         else:
#             self.__fa[rootY] = rootX
#             self.__size[rootX] += self.__size[rootY]
#         self.__count -= 1
#     def isConnected(self, x: int, y: int) -> bool:
#         return self.find(x) == self.find(y)
#     def getCount(self) -> int:
#         return self.__count

# class Solution:
#     def findCircleNum(self, isConnected: List[List[int]]) -> int:
#         n = len(isConnected)
#         uf = UF(n)
#         for i in range(n):
#             for j in range(n): 
#                 if isConnected[i][j] == 1:
#                     uf.union(i, j)
#         return uf.getCount()

class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        graph = [[] for _ in range(n)]
        for i in range(n):
            for j in range(n):
                if isConnected[i][j] == 1:
                    graph[i].append(j)
        queue = []
        visited = [0 for _ in range(n)]
        cnt = 0
        for v in range(n):
            if not visited[v]:
                queue.append(v)
                cnt += 1
                while queue:
                    cur = queue.pop(0)
                    visited[cur] = 1
                    for u in graph[cur]:
                        if not visited[u]:
                            queue.append(u)
        return cnt
# @lc code=end

