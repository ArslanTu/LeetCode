/*
 * @lc app=leetcode.cn id=2352 lang=cpp
 *
 * [2352] 相等行列对
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
using namespace std;

// @lc code=start
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> mp;
        for (auto& row : grid) ++mp[row];
        int ans = 0;
        for (int i = 0; i < grid[0].size(); ++i) {
            vector<int> col(grid.size());
            for (int j = 0; j < grid.size(); ++j) {
                col[j] = grid[j][i];
            }
            ans += mp[col];
            col.clear();
        }
        return ans;
    }
};
// @lc code=end

