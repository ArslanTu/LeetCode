/*
 * @lc app=leetcode.cn id=2369 lang=cpp
 *
 * [2369] 检查数组是否存在有效划分
 */
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;

// @lc code=start
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp (n+1,false);
        dp[0] = true;

        for (int i = 1; i <= n; ++i) {
            if (i >= 2 && dp[i - 2] && nums[i - 1] == nums[i - 2]) dp[i] = true;
            if (i >= 3 && dp[i - 3] && ((nums[i - 1] == nums[i-2] && nums[i -2] == nums[i - 3])||(nums[i - 1] - nums[i - 2] == 1 && nums[i - 2] - nums[i - 3] == 1))) dp[i] = true;
        }
        return dp[n];
    }
};
// @lc code=end

