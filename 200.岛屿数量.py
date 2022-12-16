#
# @lc app=leetcode.cn id=200 lang=python3
#
# [200] 岛屿数量
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

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        uf = UF(m * n)
        dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        for i in range(m):
            for j in range(n):
                if grid[i][j] == "1":
                    for dir in dirs:
                        newI = i + dir[0]
                        newJ = j + dir[1]
                        if (newI >= 0 and newI < m) and (newJ >= 0 and newJ < n) and grid[newI][newJ] == "1":
                            uf.union(i * n + j, newI * n + newJ)
        islands = set()
        for i in range(m):
            for j in range(n):
                if grid[i][j] == "1": islands.add(uf.find(i * n + j))
        return len(islands)
# @lc code=end

