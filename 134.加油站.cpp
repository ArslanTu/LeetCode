/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
#include <vector>
#include <algorithm>
using std::vector;
using std::min;
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int minSur=INT_MAX;
        int curSum=0;
        for (int i=0;i<gas.size();++i) {
            int rest=gas[i]-cost[i];
            curSum+=rest;
            minSur=min(minSur,curSum);
        }
        if (curSum<0) return -1;
        if (minSur>=0) return 0;
        for (int i=gas.size()-1;i>=0;--i) {
            minSur+=gas[i]-cost[i];
            if (minSur>=0) return i;
        }
        return -1;
    }
};
// @lc code=end
