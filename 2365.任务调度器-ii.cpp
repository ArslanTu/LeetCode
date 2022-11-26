/*
 * @lc app=leetcode.cn id=2365 lang=cpp
 *
 * [2365] 任务调度器 II
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
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long ans = 1;
        int n = tasks.size();
        int i = 0;
        map<long, long> last;
        while (i < n) {
            if (last[tasks[i]] == 0 || ans > last[tasks[i]] + space) {
                last[tasks[i]] = ans;
                ++i;
                ++ans;
            } else ans =  last[tasks[i]] + space + 1;
        }
        return ans - 1;
    }
};
// @lc code=end

