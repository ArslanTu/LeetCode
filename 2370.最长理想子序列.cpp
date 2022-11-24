/*
 * @lc app=leetcode.cn id=2370 lang=cpp
 *
 * [2370] 最长理想子序列
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
    int longestIdealString(string s, int k) {
        // int n = s.size();
        // vector<int> dp(n, 1);
        // int ans = INT_MIN;
        // for (int i = 1; i < n; ++i) {
        //     for (int j = 0; j < i; ++j) {
        //         if (s[i] - s[j] <= k && s[i] - s[j] >= -k) dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
        //         ans = ans > dp[i] ? ans : dp[i];
        //     }
        // }
        // return ans;
        vector<int> dp(26);
        int ans = INT_MIN;
        for (char ch : s) {
            ch -= 'a';
            dp[ch] = 1 + *max_element(dp.begin() + max(ch - k, 0), dp.begin() + min(ch + k + 1, 26));
            ans = ans > dp[ch] ? ans : dp[ch];
        }
        return ans;
        
    }
};
// @lc code=end

