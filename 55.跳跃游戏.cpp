/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
#include <vector>

using std::vector;
using std::max;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size()==1) return true;
        int des=nums[0];
        for (int i=1;i<nums.size()-1;++i) {
            if (i>des) return false;
            else {
                des=max(des,i+nums[i]);
            }
        }
        return des>=nums.size()-1;
    }
};
// @lc code=end

