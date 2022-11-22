/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include <vector>
using std::vector;
using std::max;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        int result=1;
        for (int i=0;i<nums.size();++i) {
            for (int j=0;j<i;++j) {
                if (nums[i]>nums[j]) dp[i]=max(dp[i],dp[j]+1);
            }
            result=max(result,dp[i]);
        }
        return result;
    }
};
// @lc code=end

