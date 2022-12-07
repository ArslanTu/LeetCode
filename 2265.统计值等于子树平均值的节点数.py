#
# @lc app=leetcode.cn id=2265 lang=python3
#
# [2265] 统计值等于子树平均值的节点数
#
from asyncio.windows_events import NULL
from typing import List, Optional

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
class Solution:
    def postOrder(self, root: TreeNode, ans: List[int]) -> List:
        if (root == None): return [0, 0]
        left = self.postOrder(root.left, ans)
        right = self.postOrder(root.right, ans)
        totalVal = root.val + left[0] + right[0]
        totalCnt = 1 + left[1] + right[1]
        if int(totalVal / totalCnt) == root.val: ans[0] += 1
        return [totalVal, totalCnt]
    
    def averageOfSubtree(self, root: Optional[TreeNode]) -> int:
        ans = [0]
        self.postOrder(root, ans)
        return ans[0]
# @lc code=end

