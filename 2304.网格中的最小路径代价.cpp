/*
 * @lc app=leetcode.cn id=2304 lang=cpp
 *
 * [2304] 网格中的最小路径代价
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
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) dp[0][i] = grid[0][i];
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int minCost = INT_MAX;
                for (int k = 0; k < n; ++k) {
                    int cost = dp[i - 1][k] + moveCost[grid[i - 1][k]][j];
                    minCost = min(minCost, cost);
                }
                dp[i][j] = minCost + grid[i][j];
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, dp[m - 1][i]);
        }
        return ans;
    }
};
// @lc code=end

