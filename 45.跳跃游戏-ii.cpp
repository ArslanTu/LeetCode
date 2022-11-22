/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
#include <vector>
using std::vector;
using std::max;
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size()==1) return 0;
        int res=0;
        int curDis=0,nextDis=0;
        for (int i=0;i<nums.size();++i) {
            nextDis=max(nextDis,i+nums[i]);
            if (curDis==i) {
                if (i!=nums.size()-1) {
                    res++;
                    curDis=nextDis;
                    if (curDis>=nums.size()-1) break;
                }
                else break;
            }
        }
        return res;
    }
};
// @lc code=end

