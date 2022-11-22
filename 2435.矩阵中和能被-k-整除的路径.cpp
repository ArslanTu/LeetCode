/*
 * @lc app=leetcode.cn id=2435 lang=cpp
 *
 * [2435] 矩阵中和能被 K 整除的路径
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        vector<vector<vector<int>>> dp(grid.size()+1,vector<vector<int>>(grid[0].size()+1,vector<int>(k,0)));
        dp[0][1][0]=1;
        for (int i=0;i<grid.size();++i) {
            for (int j=0;j<grid[0].size();++j) {
                for (int m=0;m<k;++m) {
                    dp[i+1][j+1][(m+grid[i][j])%k]=(dp[i+1][j][m]+dp[i][j+1][m])%(1000000007);
                }
            }
        }
        return dp[grid.size()][grid[0].size()][0];
    }
};
// @lc code=end

