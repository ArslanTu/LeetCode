/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        if (stones.size()==1) return stones[0];
        vector<int> dp(15001,0);
        int sum=0;
        for (int stone:stones) sum+=stone;
        int target=sum/2;
        for (int i=0;i<stones.size();++i) {
            for (int j=target;j>=stones[i];--j) {
                dp[j]=max(dp[j],dp[j-stones[i]]+stones[i]);
            }
        }
        return sum-2*dp[target];
    }
};
// @lc code=end

