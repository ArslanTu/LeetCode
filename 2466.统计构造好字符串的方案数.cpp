/*
 * @lc app=leetcode.cn id=2466 lang=cpp
 *
 * [2466] 统计构造好字符串的方案数
 */
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;

// @lc code=start
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, 0);
        vector<int> item(2);
        int MOD=1e9+7;
        item[0] = zero;
        item[1] = one;
        dp[zero] += 1;
        dp[one] += 1;
        for (int i = 1; i <= high; ++i) {
            for (int j = 0; j < 2; ++j) {
                if(i >= item[j]) {
                    dp[i] = (dp[i] + dp[i-item[j]])%MOD;
                }
            }
        }
        int ans = 0;
        for (int i = low; i <= high; ++i) ans=(ans + dp[i])%MOD;
        return ans;
    }
};
// @lc code=end

