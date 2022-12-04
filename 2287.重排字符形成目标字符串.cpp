/*
 * @lc app=leetcode.cn id=2287 lang=cpp
 *
 * [2287] 重排字符形成目标字符串
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
    int rearrangeCharacters(string s, string target) {
        vector<int> targetNum(26, 0);
        for (auto& ch : target) targetNum[ch - 'a']++;
        vector<int> sNum(26, 0);
        for (auto& ch : s) sNum[ch - 'a']++;
        int ans = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            if (targetNum[i]) {
                ans = min((sNum[i] / targetNum[i]), ans);
            }
        }
        return ans;
    }
};
// @lc code=end

