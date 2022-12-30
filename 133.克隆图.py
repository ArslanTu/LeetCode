#
# @lc app=leetcode.cn id=133 lang=python3
#
# [133] 克隆图
#
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        nodes = [None for _ in range(101)]
        def construct(root: Node) -> Node:
            if not root: return None
            if nodes[root.val]:
                return nodes[root.val]
            res = Node(root.val, [])
            nodes[root.val] = res
            for f in root.neighbors:
                res.neighbors.append(construct(f))
            return res
        return construct(node)
# @lc code=end

