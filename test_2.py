from typing import List


class Solution:
    def maximumTastiness(self, price: List[int], k: int) -> int:
        price.sort()
        n = len(price)
        l, r = 0, price[n - 1] - price[0] # 确定答案上下限
        ans = 0
        while l <= r:
            m = (l + r) >> 1
            # 开始 check
            cnt, x, idx = 1, price[0], 1
            while idx < n and cnt < k:
                if price[idx] >= x + m:
                    x = price[idx]
                    cnt += 1
                idx += 1

            if cnt == k:
                ans = ans if ans > m else m # 满足条件，向右继续
                l = m + 1
            else: r = m - 1 # 不满足，向左继续
            
        return ans