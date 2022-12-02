/*
 * @lc app=leetcode.cn id=2305 lang=cpp
 *
 * [2305] 公平分发饼干
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
private:
    int ans = INT_MAX;
    void backtracking(vector<int>& cookies, int cookie, const int& n, vector<int>& children, const int& k) {
        if (cookie == n) {
            ans = min(ans, *max_element(children.begin(), children.end()));
            return;
        }
        for (int i = 0; i < k; ++i) {
            children[i] += cookies[cookie];
            backtracking(cookies, cookie + 1, n, children, k);
            children[i] -= cookies[cookie];
        }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        ans = INT_MAX;
        vector<int> children(k, 0);
        backtracking(cookies, 0, cookies.size(), children, k);
        return ans;
    }
};
// @lc code=end

