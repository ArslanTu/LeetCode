/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int arr[2] = {-1,-1};
        vector<int> ans(arr,arr+2);
        for(int i = 0;i < nums.size();++i){
            for (int j = 0; j < nums.size(); ++j)
            {
                if(i==j) continue;
                else if (nums[i]+nums[j]==target)
                {
                    ans[0]=i;
                    ans[1]=j;
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

