/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution {
public:
    int numTrees(int n) {
        if (n<=2) return n;
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for (int i=3;i<=n;++i) {
            for (int j=0;j<i;++j) {
                dp[i]+=dp[j]*dp[i-1-j];
            }
        }
        return dp[n];
    }
};
// @lc code=end

