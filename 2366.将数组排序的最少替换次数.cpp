/*
 * @lc app=leetcode.cn id=2366 lang=cpp
 *
 * [2366] 将数组排序的最少替换次数
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
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0LL;
        int m = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            int k = (nums[i] - 1) / m;
            ans += k;
            m = nums[i] / (k + 1);
        }
        return ans;
    }
};
// @lc code=end

