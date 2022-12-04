/*
 * @lc app=leetcode.cn id=2289 lang=cpp
 *
 * [2289] 使数组按非递减顺序排列
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
    int totalSteps(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int leftMax= nums[0];
        int left = nums[0];
        int len = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1])
        }
        return ans;
    }
};
// @lc code=end

