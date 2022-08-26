/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0) return 0;
        //将头部数组视为已处理部分
        //顺次检查未处理部分
        int j=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=val) nums[j++]=nums[i];
        }
        return j;
    }
};
// @lc code=end

