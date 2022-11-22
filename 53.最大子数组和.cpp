/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
#include <vector>
#include <algorithm>

using std::vector;
using std::max;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 贪心算法
        // int res=INT_MIN,count=0;
        // for (int i=0;i<nums.size();++i) {
        //     count+=nums[i];
        //     if (count >res) res=count;
        //     if (count <=0) count =0;
        // }
        // return res;

        // dp
        int res=nums[0];
        vector<int> dp(nums.size(),INT_MIN);
        dp[0]=nums[0];
        for (int i=1;i<nums.size();++i) {
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
            res=max(res,dp[i]);
        }
        return res;
        
    }
};
// @lc code=end

