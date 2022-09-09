/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

// @lc code=start
#include <vector>
using std::vector;
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int sum=0;
        for(int i=0;i<timeSeries.size();++i) sum += (i==timeSeries.size()-1||timeSeries[i+1]-timeSeries[i]>=duration)?duration:timeSeries[i+1]-timeSeries[i];
        return sum;
    }
};
// @lc code=end

