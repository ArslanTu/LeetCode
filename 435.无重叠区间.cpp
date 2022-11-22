/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
#include <vector>
#include <algorithm>
using std::sort;
using std::vector;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int res=0;
        for (int i=intervals.size()-2;i>=0;--i) {
            if (intervals[i][1]>intervals[i+1][0]) {
                intervals[i]=intervals[i+1];
                ++res;
            }
        }
        return res;
    }
    static bool cmp(const vector<int>& a,const vector<int>& b) {
        if (a[0]==b[0]) return a[1]<b[1];
        return a[0]<b[0];
    }
};
// @lc code=end

