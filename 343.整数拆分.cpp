/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution {
public:
    int integerBreak(int n) {
        int m=n<7?6:n;
        vector<int> dp(m+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        dp[3]=2;
        dp[4]=4;
        dp[5]=6;
        dp[6]=9;
        for (int i=7;i<m+1;++i) {
            dp[i]=3*dp[i-3];
        }
        return dp[n];
    }
};
// @lc code=end

