/*
 * @lc app=leetcode.cn id=2327 lang=cpp
 *
 * [2327] 知道秘密的人数
 */
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n, 0);
        const int MOD = 1000000007;
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = i + delay; j < i + forget; ++j) {
                if (j < n) {
                    dp[j] += dp[i];
                    dp[j] %= MOD;
                }
            }
        }
        int ans = 0;
        for (int i = n - forget; i < n; ++i) {
            ans = (ans + dp[i]) % MOD;
        }
        return ans;
    }
};
// @lc code=end

