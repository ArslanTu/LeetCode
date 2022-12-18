from collections import defaultdict
from typing import List


class Solution:
    def similarPairs(self, words: List[str]) -> int:
        dicts = defaultdict(int)
        for word in words:
            dic = [0 for i in range(26)]
            for ch in word: dic[ord(ch) - ord("a")] = 1
            dicts[dic] += 1
        ans = 0
        keys = dicts.keys()
        for key in keys:
            if (dicts[key] > 1): ans += dicts[key] * (dicts[key] - 1) // 2
        return ans