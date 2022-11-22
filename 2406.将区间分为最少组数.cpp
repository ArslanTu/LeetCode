/*
 * @lc app=leetcode.cn id=2406 lang=cpp
 *
 * [2406] 将区间分为最少组数
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <queue>
using namespace std;
class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b) {
        if (a[0]<b[0]) return true;
        else if (a[0]==b[0]) return a[1]<b[1];
        else return false;
    }
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int n=intervals.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        for (auto& elem:intervals) {
            if (!pq.empty()&&elem[0]>pq.top()) pq.pop();
            pq.push(elem[1]);
        }       
        return pq.size();
    }
};
// @lc code=end

