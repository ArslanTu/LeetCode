#
# @lc app=leetcode.cn id=130 lang=python3
#
# [130] 被围绕的区域
#

# @lc code=start
from typing import List


class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m, n = len(board), len(board[0])
        # 多建一个dummy作为所有边缘O的父节点
        fa = list(range(m * n + 1))
        sz = [1 for i in range(m * n + 1)]
        def find(x: int) -> int:
            if fa[x] != x: fa[x] = find(fa[x])
            return fa[x]
        def union(x: int, y: int) -> None:
            rootX = find(x)
            rootY = find(y)
            if rootX == rootY: return
            if sz[rootX] <= sz[rootY]:
                fa[rootX] = rootY
                sz[rootY] += sz[rootX]
            else:
                fa[rootY] = rootX
                sz[rootX] += sz[rootY]
        def isConnected(x: int, y: int) -> bool: return find(x) == find(y)
        dummy = m * n
        # 将所有边缘O链接到dummy
        for i in range(m):
            if board[i][0] == "O": union(i * n, dummy)
            if board[i][n - 1] == "O": union(i * n + n - 1, dummy)
        for j in range(n):
            if board[0][j] == "O": union(j, dummy)
            if board[m - 1][j] == "O": union((m - 1) * n + j, dummy)
        # 链接内圈O
        dir = [[-1, 0], [0, -1], [1, 0], [0, 1]]
        for i in range(1, m - 1):
            for j in range(1, n - 1):
                if board[i][j] == "O":
                    for newDir in dir:
                        newI = i + newDir[0]
                        newJ = j + newDir[1]
                        if board[newI][newJ] == "O":
                            union(i * n + j, newI * n + newJ)
        # 修改没有链接到dummy的O
        for i in range(m):
            for j in range(n):
                if (board[i][j] == "O") and (not isConnected(i * n + j, dummy)):
                    board[i][j] = "X"
# @lc code=end

