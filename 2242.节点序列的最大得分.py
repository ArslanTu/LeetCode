#
# @lc app=leetcode.cn id=2242 lang=python3
#
# [2242] 节点序列的最大得分
#

# @lc code=start
from cmath import inf
from typing import List


class Solution:
    ans = -inf
    def dfs(self, scores: List[int], pic: List[List[int]], path: int, pathSum: int, cur:int, visited: List[int]) -> None:
        path += 1
        visited[cur] = 1
        pathSum += scores[cur]
        if path == 4: self.ans = self.ans if self.ans > pathSum else pathSum
        else:
            for next in pic[cur]:
                if visited[next] == 0:
                    self.dfs(scores, pic, path, pathSum, next, visited)
        path -= 1
        visited[cur] = 0
        pathSum -= scores[cur]
        return
    
    def maximumScore(self, scores: List[int], edges: List[List[int]]) -> int:
        n = len(scores)
        self.ans = -inf
        pic = [[] for i in range(n)]
        for edge in edges:
            pic[edge[0]].append(edge[1])
            pic[edge[1]].append(edge[0])
        visited = [0 for i in range(n)]
        for i in range(n):
            self.dfs(scores, pic, 0, 0, i, visited)
        return self.ans if self.ans != -inf else -1
# @lc code=end

