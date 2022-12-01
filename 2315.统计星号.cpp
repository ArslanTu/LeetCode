/*
 * @lc app=leetcode.cn id=2315 lang=cpp
 *
 * [2315] 统计星号
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
    int countAsterisks(string s) {
        bool flag = false;
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (!flag) {
                if (s[i] != '|') {
                    if (s[i] == '*') ++ans;
                }
                else flag  =true;
            }
            else {
                if (s[i] == '|') flag = false;
            }
        }
        return ans;
    }
};
// @lc code=end

