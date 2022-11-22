/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1) return 0;
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,1));
        for (int c=0;c<n;++c) {
            if (obstacleGrid[0][c]==1) {
                for (int i=c;i<n;++i) dp[0][i]=0;
                break;
            }
        }
        for (int r=0;r<m;++r) {
            if (obstacleGrid[r][0]==1) {
                for (int i=r;i<m;++i) dp[i][0]=0;
                break;
            }
        }
        for (int r=1;r<m;++r) {
            for (int c=1;c<n;++c) {
                if (obstacleGrid[r][c]==1) dp[r][c]=0;
            }
        }
        for (int r=1;r<m;++r) {
            for (int c=1;c<n;++c) {
                if (dp[r][c]!=0) dp[r][c]=dp[r-1][c]+dp[r][c-1];
            }
        }
        return dp[m-1][n-1];
    }
};
// @lc code=end

