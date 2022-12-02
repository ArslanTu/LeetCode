/*
 * @lc app=leetcode.cn id=2309 lang=cpp
 *
 * [2309] 兼具大小写的最好英文字母
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
    string greatestLetter(string s) {
        vector<int> vec(26, -1);
        for (auto& ch : s) {
            if (ch - 'a' >= 0 && ch - 'a' < 26) {
                if (vec[ch - 'a'] == -1) vec[ch - 'a'] = 0;
                else if (vec[ch - 'a'] == 1) vec[ch - 'a'] = 2;
            }
            else {
                if (vec[ch - 'A'] == -1) vec[ch - 'A'] = 1;
                else if (vec[ch - 'A'] == 0) vec[ch - 'A'] = 2;
            }
        }
        string ans = "";
        for (int i = 25; i >=0; --i) {
            if (vec[i] == 2) {
                ans += char('A' + i);
                return ans;
            }
        }
        return ans;
    }
};
// @lc code=end

