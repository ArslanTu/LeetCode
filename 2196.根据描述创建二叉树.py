#
# @lc app=leetcode.cn id=2196 lang=python3
#
# [2196] 根据描述创建二叉树
#
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import defaultdict
from typing import List, Optional


class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        parents = set()
        children = set()
        dic = defaultdict(list[list[int]])
        for p, c, isL in descriptions:
            parents.add(p)
            children.add(c)
            dic[p].append([c, isL])
        parents = list(parents)
        rootVal = -1
        for p in parents:
            if p not in children: rootVal = p
        root = TreeNode(rootVal)
        stack = [root]
        while stack:
            cur = stack.pop()
            for children in dic[cur.val]:
                child = TreeNode(children[0])
                if children[1] == 1:
                    cur.left = child
                else:
                    cur.right = child
                stack.append(child)
        return root
# @lc code=end

sl = Solution()
p1 = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
sl.createBinaryTree(p1)