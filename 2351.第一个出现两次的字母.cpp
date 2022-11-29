/*
 * @lc app=leetcode.cn id=2351 lang=cpp
 *
 * [2351] 第一个出现两次的字母
 */
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include  <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char, int> ump;
        for (auto& ch : s) {
            ++ump[ch];
            if (ump[ch] == 2) return ch;
        }
        return '0';
    }
};
// @lc code=end

