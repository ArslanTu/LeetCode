/*
 * @lc app=leetcode.cn id=2299 lang=cpp
 *
 * [2299] 强密码检验器 II
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
    bool strongPasswordCheckerII(string password) {
        if (password.size() < 8) return false;
        bool small = false, big = false, num = false, special = false, same = true;
        for (int i = 0; i < password.size(); ++i) {
            if (password[i] - 'a' >= 0 && password[i] - 'a' < 26) small = true;
            else if (password[i] - 'A' >= 0 && password[i] - 'A' < 26) big = true;
            else if (password[i] - '0' >= 0 && password[i] - '0' < 10) num = true;
            else if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*' || password[i] == '(' || password[i] == ')' || password[i] == '-' || password[i] == '+') special = true;
            if (i > 0) {
                if (password[i] == password[i - 1]) same = false;
            }
        }
        return small && big && num && special && same;
    }
};
// @lc code=end

