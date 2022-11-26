/*
 * @lc app=leetcode.cn id=2360 lang=cpp
 *
 * [2360] 图中的最长环
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
    int longestCycle(vector<int>& edges) {
        int ans = -1;
        int n = edges.size();
        vector<int> time(n, 0);
        for (int i = 0, clock = 1; i < n; ++i) {
            if (time[i]) continue;
            for (int x = i, startTime = clock; x >= 0; x = edges[x]) {
                if (time[x]) {
                    if (time[x] >= startTime) {
                        ans = max(ans, clock - time[x]);
                    }
                    break;
                }
                time[x] = clock++;
            }
        }
        return ans;
    }
};
// @lc code=end

