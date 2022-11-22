/*
 * @lc app=leetcode.cn id=2460 lang=cpp
 *
 * [2460] 对数组执行操作
 */

// @lc code=start
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for (int i=0;i<nums.size()-1;++i) {
            if (nums[i]==nums[i+1]) {
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        int count=0;
        for (vector<int>::iterator iter=nums.begin();iter!=nums.end();) {
            if (*iter==0) {
                nums.erase(iter);
                ++count;
            }
            else ++iter;
        }
        for (int i=0;i<count;++i) nums.push_back(0);
        return nums;
    }
};
// @lc code=end

