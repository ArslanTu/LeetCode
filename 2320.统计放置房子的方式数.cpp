/*
 * @lc app=leetcode.cn id=2320 lang=cpp
 *
 * [2320] 统计放置房子的方式数
 */

// @lc code=start
class Solution {
public:
    int countHousePlacements(int n) {
        long long dp[n + 1];
        dp[0] = 1;
        dp[1] = 2;
        const int MOD = 1000000007;
        for (int i = 2; i <= n; ++i) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }
        return (dp[n] * dp[n]) % MOD;
    }
};
// @lc code=end

