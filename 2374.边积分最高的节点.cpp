/*
 * @lc app=leetcode.cn id=2374 lang=cpp
 *
 * [2374] 边积分最高的节点
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
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> score(n,0);
        for (int i = 0; i < n; ++i) score[edges[i]] += i;
        int ans=-1;
        long long maxScore=LONG_LONG_MIN;
        for (int i = n - 1; i >= 0; --i) {
            if (score[i] >= maxScore) {
                maxScore = score[i];
                ans = i;
            }
        }
        return ans;
    }
};
// @lc code=end

