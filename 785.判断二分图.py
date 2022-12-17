#
# @lc app=leetcode.cn id=785 lang=python3
#
# [785] 判断二分图
#

# @lc code=start
from typing import List

class UF:
    __fa = []
    __size = []
    __count = 0
    def __init__(self, n: int) -> None:
        self.__fa = list(range(n))
        self.__size = [1 for i in range(n)]
        self.__count = n
    def find(self, x: int) -> int:
        if self.__fa[x] != x: self.__fa[x] = self.find(self.__fa[x])
        return self.__fa[x]
    def union(self, x: int, y: int) -> None:
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX == rootY: return
        if self.__size[rootX] <= self.__size[rootY]:
            self.__fa[rootX] = rootY
            self.__size[rootY] += self.__size[rootX]
        else:
            self.__fa[rootY] = rootX
            self.__size[rootX] += self.__size[rootY]
        self.__count -= 1
    def isConnected(self, x: int, y: int) -> bool:
        return self.find(x) == self.find(y)
    def getCount(self) -> int:
        return self.__count
    def getSize(self, x: int) -> int:
        rootX = self.find(x)
        return self.__size[rootX]

class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        uf = UF(n)
        for i in range(n):
            m = len(graph[i])
            if m == 0:
                continue
            for j in range(1, m):
                uf.union(graph[i][0], graph[i][j])
                if uf.isConnected(i, graph[i][0]):
                    return False
        return True
# @lc code=end

