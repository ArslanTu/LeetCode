#
# @lc app=leetcode.cn id=2225 lang=python3
#
# [2225] 找出输掉零场或一场比赛的玩家
#

# @lc code=start
from typing import List


class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        # winner = [0 for i in range(100001)]
        # loser = [0 for i in range(100001)]
        # ans = [[], []]
        # for match in matches:
        #     winner[match[0]] += 1
        #     loser[match[1]] += 1
        # for i in range(100001):
        #     if winner[i] > 0 and loser[i] == 0:
        #         ans[0].append(i)
        #     elif loser[i] == 1:
        #         ans[1].append(i)
        # return ans
        ans = [[], []]
        win = {}
        lose = {}
        persons = set()
        for match in matches:
            persons.add(match[0])
            persons.add(match[1])
            if match[0] not in win: win[match[0]] = 0
            if match[1] not in win: win[match[1]] = 0
            if match[0] not in lose: lose[match[0]] = 0
            if match[1] not in lose: lose[match[1]] = 0
            win[match[0]] += 1
            lose[match[1]] += 1
        persons = list(persons)
        persons.sort()
        for i in persons:
            if lose[i] == 0 and win[i] > 0: ans[0].append(i)
            elif lose[i] == 1: ans[1].append(i)
        return ans
    
# @lc code=end

