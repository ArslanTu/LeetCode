/*
 * @lc app=leetcode.cn id=2319 lang=cpp
 *
 * [2319] 判断矩阵是否是一个 X 矩阵
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
    bool checkXMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == j || i + j == m - 1) {
                    if (grid[i][j] == 0) return false;
                }
                else {
                    if (grid[i][j] != 0) return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

