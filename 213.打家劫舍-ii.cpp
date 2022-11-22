/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
#include <vector>

using std::vector;
using std::max;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        if (nums.size()==2) return max(nums[0],nums[1]);
        //删掉nums[0]计算一个终值
        vector<int> nums2(nums);
        nums2.erase(nums2.begin());
        vector<int> dp2(nums2.size());
        int fn;
        if (nums2.size()==2) fn = max(nums2[0],nums2[1]);
        else {
            dp2[0]=nums2[0];
            dp2[1]=max(nums2[0],nums2[1]);
            for (int i=2;i<nums2.size();++i) {
                dp2[i] = max(dp2[i-1],dp2[i-2]+nums2[i]);
            }
            fn=dp2[nums2.size()-1];
        }

        vector<int> dp(nums.size());
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for (int i=2;i<nums.size()-1;++i) {
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return max(fn,dp[nums.size()-2]);

    }
};
// @lc code=end

