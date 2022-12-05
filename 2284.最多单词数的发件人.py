#
# @lc app=leetcode.cn id=2284 lang=python3
#
# [2284] 最多单词数的发件人
#
from typing import List
# @lc code=start
class Solution:
    def largestWordCount(self, messages: List[str], senders: List[str]) -> str:
        dic = {}
        n = len(messages)
        maxCnt = 0
        maxSender = senders[0]
        for i in range(n):
            if senders[i] not in dic: dic[senders[i]] = 0
            dic[senders[i]] += messages[i].count(" ") + 1
            if dic[senders[i]] > maxCnt: 
                maxCnt = dic[senders[i]]
                maxSender = senders[i]
            elif dic[senders[i]] == maxCnt:
                if (senders[i] > maxSender): maxSender = senders[i]
        return maxSender
# @lc code=end

