/*
 * @lc app=leetcode.cn id=2428 lang=cpp
 *
 * [2428] 沙漏的最大总和
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
    int maxSum(vector<vector<int>>& grid) {
        int maxSum=INT_MIN;
        int m=grid.size(),n=grid[0].size();
        for (int i=0;i<m-2;++i) {
            for (int j=0;j<n-2;++j) {
                int sum=grid[i][j]+grid[i][j+1]+grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];
                maxSum=sum>maxSum?sum:maxSum;
            }
        }
        return maxSum;
    }
};
// @lc code=end

