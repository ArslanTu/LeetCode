/*
 * @lc app=leetcode.cn id=2294 lang=cpp
 *
 * [2294] 划分数组使最大差为 K
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
    int partitionArray(vector<int>& nums, int k) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int start = 0;
        for (int i = 0;i < n; ++i) {
            if (nums[i] - nums[start] > k) {
                ++ans;
                start = i;
            }
        }
        return ans + 1;
    }
};
// @lc code=end

