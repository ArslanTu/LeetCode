#
# @lc app=leetcode.cn id=2251 lang=python3
#
# [2251] 花期内花的数目
#

# @lc code=start
class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], persons: List[int]) -> List[int]:
        diff = defaultdict(int)  # 也可以用 SortedDict
        for start, end in flowers:
            diff[start] += 1
            diff[end + 1] -= 1
        times = sorted(diff.keys())

        n = len(persons)
        ans = [0] * n
        i = sum = 0
        for p, id in sorted(zip(persons, range(n))):
            while i < len(times) and times[i] <= p:
                sum += diff[times[i]]  # 累加变化量
                i += 1
            ans[id] = sum
        return ans
# @lc code=end

