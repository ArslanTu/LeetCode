/*
 * @lc app=leetcode.cn id=2302 lang=cpp
 *
 * [2302] 统计得分小于 K 的子数组数目
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
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0LL, sum = 0LL;
        for (int left = 0, right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            while (sum * (right - left +1) >= k) {
                sum -= nums[left++];
            }
            ans += right - left + 1;
        }
        return ans;
    }
};
// @lc code=end

