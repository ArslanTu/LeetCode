/*
 * @lc app=leetcode.cn id=2303 lang=cpp
 *
 * [2303] 计算应缴税款总额
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
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int n = brackets.size();
        double ans = 0.0;
        if (income <= brackets[0][0]) return income * brackets[0][1] * 0.01;
        ans += brackets[0][0] * brackets[0][1] * 0.01;
        for (int i = 1; i < n; ++i) {
            if (income <= brackets[i][0]) {
                ans += (income - brackets[i - 1][0]) * brackets[i][1] * 0.01;
                break;
            }
            else {
                ans += (brackets[i][0] - brackets[i - 1][0]) * brackets[i][1] * 0.01;
            }
        }
        return ans;

    }
};
// @lc code=end

