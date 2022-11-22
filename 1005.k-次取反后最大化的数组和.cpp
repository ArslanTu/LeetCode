/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        for (int i=0;i<nums.size()&&nums[i]<0&&k>0;++i) {
            nums[i]*=-1;
            --k;
        }
        sort(nums.begin(),nums.end());
        if (k%2==0) return Sum(nums);
        else {
            nums[0]*=-1;
            return Sum(nums);
        }
        
    }
    int Sum(vector<int>& nums) {
        int sum=0;
        for (int i=0;i<nums.size();++i) {
            sum+=nums[i];
        }
        return sum;
    }
};
// @lc code=end

