/*
 * @lc app=leetcode.cn id=2301 lang=cpp
 *
 * [2301] 替换字符后匹配
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
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int n = s.size(), m = sub.size();
        unordered_map<char, unordered_set<char>> mp;
        for (auto& mapping : mappings) mp[mapping[0]].emplace(mapping[1]);
        for (int i = 0; i <= n - m; ++i) {
            string t = s.substr(i, m);
            bool flag = true;
            for (int j = 0;j < m; ++j) {
                if (sub[j] == t[j]) continue;
                else {
                    if (mp[sub[j]].count(t[j])) continue;
                    else {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) return true;
        }
        return false;
    }
};
// @lc code=end

