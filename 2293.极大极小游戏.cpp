/*
 * @lc app=leetcode.cn id=2293 lang=cpp
 *
 * [2293] 极大极小游戏
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
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        while (n != 1) {
            n = n >> 1;
            for (int i = 0; i < n; ++i) {
                if ((i & 1) == 0) nums[i] = min(nums[(i << 1)], nums[(i << 1) + 1]);
                else nums[i] = max(nums[(i << 1)], nums[(i << 1) + 1]);
            }
        }
        return nums[0];
    }
};
// @lc code=end

