/*
 * @lc app=leetcode.cn id=2325 lang=cpp
 *
 * [2325] 解密消息
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
    string decodeMessage(string key, string message) {
        map<char, char> mp;
        char x = 'a';
        for (auto& k : key) if (k != ' ' && !mp[k]) mp[k] = x++;
        string ans = "";
        for (auto& m : message) {
            if (m!=' ') ans += mp[m];
            else ans += " ";
        }
        return ans;
    }
};
// @lc code=end

