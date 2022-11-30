/*
 * @lc app=leetcode.cn id=2328 lang=cpp
 *
 * [2328] 网格图中递增路径的数目
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
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1));
        const int MOD = 1000000007;
        for (int i = 1; i < n; ++i) if (grid[0][i] > grid[0][i - 1]) dp[0][i] += dp[0][i - 1];
        for (int i = 1; i < m; ++i) if (grid[i][0] > grid[i - 1][0]) dp[i][0] += dp[i - 1][0];

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (grid[i][j] > grid[i][j - 1]) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
                if (grid[i][j] > grid[i - 1][j]) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            }
        }
        
        for (int i = n - 2; i >= 0; --i) if (grid[m - 1][i] > grid[m - 1][i + 1]) dp[m - 1][i] += dp[m - 1][i + 1];
        for (int i = m - 2; i >= 0; --i) if (grid[i][n -1 ] > grid[i + 1][n -1 ]) dp[i][n -1 ] += dp[i + 1][n -1 ];
        
        for (int i = m - 2; i >=0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                if (grid[i][j] > grid[i][j + 1]) dp[i][j] = (dp[i][j] + dp[i][j + 1]) % MOD;
                if (grid[i][j] > grid[i + 1][j]) dp[i][j] = (dp[i][j] + dp[i + 1][j]) % MOD;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) ans = (ans + dp[i][j]) % MOD;
        }
        return ans;
    }
};
// @lc code=end

