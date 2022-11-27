/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
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
private:
    void backtracking(vector<string>& ans, string path, int left, int right) {
        if (!left && !right) {
            ans.push_back(path);
            return;
        }
        if (left) {
            path += "(";
            backtracking(ans, path, left - 1, right);
            path.pop_back();
        }
        if (right && right > left) {
            path += ")";
            backtracking(ans, path, left, right - 1);
            path.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtracking(ans, "", n, n);
        return ans;
    }
};
// @lc code=end

