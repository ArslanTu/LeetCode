/*
 * @lc app=leetcode.cn id=2363 lang=cpp
 *
 * [2363] 合并相似的物品
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
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        else return a[0] < b[0];
    }
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> ans;
        map<int,int> mp;
        for (auto& item1 : items1) mp[item1[0]] += item1[1];
        for (auto& item2 : items2) mp[item2[0]] += item2[1];
        for (auto& elem : mp) ans.push_back({elem.first, elem.second});
        // sort(ans.begin(), ans.end(), cmp);
        return ans;
    }
};
// @lc code=end

