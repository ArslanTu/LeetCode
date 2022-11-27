/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
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
    int reverse(int x) {
        string sx = to_string(x);
        string sy(sx.rbegin(), sx.rend());
        if (sx[0] == '-') sy.pop_back();
        int y = 0;
        for (int i = 0; i < sy.size(); ++i) {
            if (y > (1LL << 31) / 10) return 0;
            y = y * 10 + (sy[i] - '0');
        }
        if (sx[0] == '-') y *= -1;
        return y;
    }
};
// @lc code=end

