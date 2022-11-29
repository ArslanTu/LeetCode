/*
 * @lc app=leetcode.cn id=2348 lang=cpp
 *
 * [2348] 全 0 子数组的数目
 */
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        // vector<long long> dp(nums.size(), 0L);
        // if (nums[0] == 0) dp[0] = 1L;
        // long long ans = dp[0];
        // for (int i = 1; i < nums.size(); ++i) {
        //     if (nums[i] == 0) {
        //         if (nums[i - 1] == 0) dp[i] = dp[i - 1] + 1;
        //         else dp[i] = 1;
        //         ans += dp[i];
        //     }
        // }
        // return ans;
        long long ans = 0L;
        long long cnt = 0L;
        for (auto& num : nums) {
            if (num == 0) ++cnt;
            else {
                ans += (1 + cnt) * cnt / 2;
                cnt = 0;
            }
        }
        ans += (1 + cnt) * cnt / 2;
        return ans;
    }
};
// @lc code=end

