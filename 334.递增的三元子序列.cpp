/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size()<3) return false;
        int small=nums[0],mid;
        int k=1;
        while (k<nums.size()) {
            if (nums[k]<=small) small=nums[k];
            else {
                mid=nums[k];
                break;
            }
            ++k;
        }
        if (k==nums.size()-1) return false;
        for (int i=k+1;i<nums.size();++i) {
            if (nums[i]<=small) small=nums[i];
            else if (nums[i]<=mid) mid=nums[i];
            else return true;
        }
        return false;
    }
};
// @lc code=end

