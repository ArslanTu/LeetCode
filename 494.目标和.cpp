/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        if (nums.size()==1&&(nums[0]+target!=0&&nums[0]!=target)) return 0;
        vector<int> dp(1001,0);
        int sum=0;
        dp[0]=1;
        for (int num:nums) sum+=num;
        if ((sum+target)%2==1) return 0;
        int x = (sum+target)/2;
        for (int i=0;i<nums.size();++i) {
            for (int j=x;j>=nums[i];--j) {
                dp[j]+=dp[j-nums[i]];
            }
        }
        return dp[x];
    }
};
// @lc code=end

