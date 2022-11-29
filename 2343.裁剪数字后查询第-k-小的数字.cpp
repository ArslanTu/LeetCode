/*
 * @lc app=leetcode.cn id=2343 lang=cpp
 *
 * [2343] 裁剪数字后查询第 K 小的数字
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
#include <numeric>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries) {
        vector<int> ans(queries.size());
        int n = nums.size(), m = nums[0].length();
        vector<int> index(n,0);
        for (int i = 0; i < queries.size(); ++i) {
            iota(index.begin(), index.end(), 0);
            auto& qur = queries[i];
            stable_sort(index.begin(), index.end(), [&] (int a, int b) -> bool {
                auto& s = nums[a], &t = nums[b];
                for (int j = m - qur[1]; j < m; ++j) {
                    if (s[j] != t[j]) return s[j] < t[j];
                }
                return false;
            });
            ans[i] = index[qur[0] - 1];
        }
        return ans;
    }
};
// @lc code=end

