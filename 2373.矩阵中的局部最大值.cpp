/*
 * @lc app=leetcode.cn id=2373 lang=cpp
 *
 * [2373] 矩阵中的局部最大值
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
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans;
        vector<int> row;
        int n = grid.size();
        for (int i = 0; i < n - 2; ++i) {
            row.clear();
            for (int j = 0; j < n - 2; ++j) {
                int maxNum=INT_MIN;
                for (int k = i; k < i + 3; ++k) {
                    for (int l = j; l < j + 3; ++l) {
                        maxNum=max(maxNum, grid[k][l]);
                    }
                }
                row.push_back(maxNum);
                maxNum=INT_MIN;
            }
            ans.push_back(row);
        }
        return ans;
    }
};
// @lc code=end

