#
# @lc app=leetcode.cn id=2283 lang=python3
#
# [2283] 判断一个数的数字计数是否等于数位的值
#

# @lc code=start
class Solution:
    def digitCount(self, num: str) -> bool:
        dic = {}
        n = len(num)
        for i in range(n):
            if (int(num[i], 10) in dic): dic[int(num[i], 10)] += 1
            else: dic[int(num[i], 10)] = 1
        for i in range(n):
            if ((int(num[i], 10) == 0 and i in dic) or (int(num[i], 10) != 0 and (i not in dic or dic[i] != int(num[i], 10)))): return False
        return True
# @lc code=end


