#
# @lc app=leetcode.cn id=692 lang=python3
#
# [692] 前K个高频单词
#

# @lc code=start
from collections import defaultdict
from heapq import heappush, nlargest
from typing import List


class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        dic = defaultdict(int)
        for word in words: dic[word] += 1
        words = list(dic.keys())
        words.sort(reverse=True)
        hp = []
        for i in range(len(words)):
            heappush(hp, [dic[words[i]], i])
        res = nlargest(k, hp)
        ans = [words[res[i][1]] for i in range(len(res))]
        return ans
# @lc code=end

