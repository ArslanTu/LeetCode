#
# @lc app=leetcode.cn id=2273 lang=python3
#
# [2273] 移除字母异位词后的结果数组
#
from typing import List
# @lc code=start
class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        wordsDic = []
        n = len(words)
        for i in range(n):
            dic = {}
            for ch in words[i]:
                if ch not in dic: dic[ch] = 1
                else: dic[ch] += 1
            wordsDic.append(dic)
        ans = [words[0]]
        start = 0
        for i in range(1, n):
            if wordsDic[i] != wordsDic[start]:
                start = i
                ans.append(words[i])
        return ans
# @lc code=end

