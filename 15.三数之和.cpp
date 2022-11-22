/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size()<3) return res;
        sort(nums.begin(),nums.end());
        for (int i=0;i<nums.size();++i) {
            if (nums[i]>0) return res;
            else if ( i>0 && nums[i]==nums[i-1]) continue;
            else {
                int L = i+1,R = nums.size()-1;
                while(L<R) {
                    if(nums[i]+nums[L]+nums[R]==0) {
                        vector<int> entry;
                        entry.push_back(nums[i]);
                        entry.push_back(nums[L]);
                        entry.push_back(nums[R]);
                        res.push_back(entry);
                        while(L<R && nums[L]==nums[L+1]) ++L;
                        while(L<R && nums[R]==nums[R-1]) --R;
                        ++L;--R;
                    }
                    else if (nums[i]+nums[L]+nums[R] >0) --R;
                    else ++L;
                }
            }
        }
        return res;
    }
};
// @lc code=end

