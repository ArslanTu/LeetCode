/*
 * @lc app=leetcode.cn id=2462 lang=cpp
 *
 * [2462] 雇佣 K 位工人的总代价
 */

// @lc code=start
#include <vector>
#include <algorithm>
using std::sort;
using std::vector;
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int res=0;
        int chosen=0;
        while (chosen<=k&&costs.size()>=candidates) {
            
        }
        if (chosen<k&&costs.size()!=0) {
            sort(costs.begin(),costs.end());
            for (int i=0;i<k-chosen;++i) {
                res+=costs[i];
            }
        }
        return res;
    }
};
// @lc code=end

