#
# @lc app=leetcode.cn id=744 lang=python3
#
# [744] 寻找比目标字母大的最小字母
#

# @lc code=start
from typing import List


class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        ans = ""
        for letter in letters:
            if letter > target:
                if ans == "": ans = letter
                else:
                    if letter < ans: ans = letter
        return ans if ans != "" else letters[0]
# @lc code=end

