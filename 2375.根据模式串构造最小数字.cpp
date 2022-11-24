/*
 * @lc app=leetcode.cn id=2375 lang=cpp
 *
 * [2375] 根据模式串构造最小数字
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
    string smallestNumber(string pattern) {
        int i = 0, n = pattern.length();
        char cur = '1';
        string ans(n + 1, 0);
        while (i < n) {
            if (i && pattern[i] == 'I') ++i;
            for (; i < n && pattern[i] == 'I'; ++i) ans[i] = cur++;
            int i0 = i;
            while (i < n && pattern[i] == 'D') ++i;
            for (int j = i; j >= i0; --j) ans[j] = cur++;
        }
        return ans;
    }
};
// @lc code=end

