#
# @lc app=leetcode.cn id=2182 lang=python3
#
# [2182] 构造限制重复的字符串
#

# @lc code=start
class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        nums = [0 for i in range(26)]
        for c in s:
            nums[ord(c) - ord('a')] += 1
        ans = ""
        cnt = 0
        i = 25
        while nums[i] == 0 and i >= 0:
            i -= 1
        while i >=0:
            ans += chr(ord('a') + i)
            cnt += 1
            nums[i] -= 1
            while nums[i] == 0 and i >= 0:
                i -= 1
                cnt = 0
            if cnt == repeatLimit:
                j = i - 1
                while nums[j] == 0 and j >= 0: j -= 1
                if j == -1: return ans
                ans += chr(ord('a') + j)
                nums[j] -= 1
                cnt = 0
        return ans
# @lc code=end

p1 = "robnsdvpuxbapuqgopqvxdrchivlifeepy"
p2 = 2
sl = Solution()
print(sl.repeatLimitedString(p1, p2) == "yxxvvuvusrrqqppopponliihgfeeddcbba")