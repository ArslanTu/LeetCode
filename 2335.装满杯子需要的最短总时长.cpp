/*
 * @lc app=leetcode.cn id=2335 lang=cpp
 *
 * [2335] 装满杯子需要的最短总时长
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
    int fillCups(vector<int>& amount) {
        int ans = 0;
        sort(amount.begin(), amount.end());
        while (amount[2] != 0) {
            amount[2]--;
            amount[1]--;
            sort(amount.begin(), amount.end());
            ++ans;
        }
        return ans;
    }
};
// @lc code=end

