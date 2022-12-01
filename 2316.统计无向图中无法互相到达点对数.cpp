/*
 * @lc app=leetcode.cn id=2316 lang=cpp
 *
 * [2316] 统计无向图中无法互相到达点对数
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
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> pic(n);
        for (auto& edge : edges) {
            pic[edge[0]] . push_back(edge[1]);
            pic[edge[1]] . push_back(edge[0]);
        }
        
    }
};
// @lc code=end

