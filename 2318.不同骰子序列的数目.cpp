/*
 * @lc app=leetcode.cn id=2318 lang=cpp
 *
 * [2318] 不同骰子序列的数目
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
    int ans = 0;
    const int MOD = 1000000007;
    const vector<vector<int>> vec = {{}, {2, 3, 4, 5, 6}, {1, 3, 5}, {1, 2, 4, 5}, {1, 3, 5}, {1, 2, 3, 4, 6}, {1, 5}};
    void backtracking(int pre, int curNum, int curN, const int& n) {
        if (curN == n) return;
        ++curN;
        for (auto& num : vec[curNum]) {
            if (num != curNum && num != pre) {
                if (curN == n) ans = (ans + 1) % MOD;
                backtracking(curNum, num, curN, n);
            }
        }
    }
public:
    int distinctSequences(int n) {
        ans = 0;
        for (int i = 1; i <= 6; ++i) {
            backtracking(-1, i, 1, n);
        }
        return ans;
    }
};
// @lc code=end

