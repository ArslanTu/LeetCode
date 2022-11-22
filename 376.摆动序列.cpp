/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size()==1) return 1;
        if (nums.size()==2&&nums[0]!=nums[1]) return 2;
        int res=1;
        int preDiff=0,curDiff=0;
        for (int i=0;i<nums.size()-1;++i) {
            curDiff=nums[i+1]-nums[i];
            if ((curDiff>0&&preDiff<=0)||preDiff>=0&&curDiff<0) {
                res++;
                preDiff=curDiff;
            }
        }
        return res;
    }
};
// @lc code=end

