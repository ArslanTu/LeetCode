/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
#include <vector>
using std::vector;
using std::max;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        // 贪心算法
        // int res=1;
        // int count=1;
        // for (int i=1;i<nums.size();++i) {
        //     if (nums[i]-nums[i-1]>0) {
        //         ++count;
        //         res=max(res,count);
        //     }
        //     else count=1;
        // }
        // return res;

        int res=1;
        vector<int> dp(nums.size(),1);
        for (int i=1;i<nums.size();++i) {
            if (nums[i]>nums[i-1]) {
                dp[i]=dp[i-1]+1;
                res=max(dp[i],res);
            }
            else {
                dp[i]=1;
            }
        }
        return res;
    }
};
// @lc code=end

