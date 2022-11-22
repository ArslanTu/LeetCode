/*
 * @lc app=leetcode.cn id=2455 lang=cpp
 *
 * [2455] 可被三整除的偶数的平均值
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum=0;
        int res=0;
        int count=0;
        int numsLen=nums.size();
        for (int i=0;i<numsLen;++i) {
            if (nums[i]%6==0) {
                ++count;
                sum+=nums[i];
            }
        }
        if (count!=0) res=sum/count;
        return res;
    }
};
// @lc code=end

