/*
 * @lc app=leetcode.cn id=2421 lang=cpp
 *
 * [2421] 好路径的数目
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
private:
    int ans = 0;
    void backtracking(vector<vector<int>>& pic, int start, int cur, int before) {
        for (int i = 0; i < pic[cur].size(); ++i) {
            if (pic[cur[i]]!=before)
        }

    }
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int ans = 0;
        // 建图
        vector<vector<int>> pic(vals.size());
        for (auto& edge : edges) {
            pic[edge[0]].push_back(edge[1]);
            pic[edge[1]].push_back(edge[0]);
        }
    }
};
// @lc code=end

