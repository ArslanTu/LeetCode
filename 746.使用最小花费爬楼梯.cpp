/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
#include <vector>
#include <algorithm>
using std::vector;
using std::min;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // vector<int> dp(cost.size()+1,0);
        // for (int i=2;i<=cost.size();++i) {
        //     dp[i]=(dp[i-2]+cost[i-2]<dp[i-1]+cost[i-1])?(dp[i-2]+cost[i-2]):(dp[i-1]+cost[i-1]);
        // }
        // return dp[cost.size()];
        vector<int> dp(2,0);
        for (int i=2;i<=cost.size();++i) {
            int sum = min(dp[0]+cost[i-2],dp[1]+cost[i-1]);
            dp[0]=dp[1];
            dp[1]=sum;
        }
        return dp[1];
    }
};
// @lc code=end

