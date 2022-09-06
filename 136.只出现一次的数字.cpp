/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
#include <vector>
#include <algorithm>
using std::sort;
using std::vector;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        for(;i<nums.size()-1;++i){
            if(nums[i]==nums[i+1]) ++i;
            else return nums[i];
        }
        return nums[i];
    }
};
// @lc code=end

