/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
#include <vector>
#include <stack>
#include <algorithm>
using std::sort;
using std::max;
using std::min;
using std::stack;
using std::vector;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // sort(points.begin(),points.end(),cmp);
        // stack<vector<int>> s;
        // for (int i=points.size()-1;i>=0;--i) s.push(points[i]);
        // int res=0;
        // while (!s.empty()) {
        //     vector<int> balloon=s.top();
        //     s.pop();
        //     if (!s.empty()&&s.top()[0]<=balloon[1]) {
        //         vector<int> newBalloon(2);
        //         newBalloon[0]=s.top()[0];
        //         newBalloon[1]=min(balloon[1],s.top()[1]);
        //         s.pop();
        //         s.push(newBalloon);
        //     }
        //     else ++res;
        // }
        // return res;
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), cmp);
        int result = 1;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > points[i - 1][1]) { 
                result++;
            }
            else {
                points[i][1] = min(points[i - 1][1], points[i][1]);
            }
        }
        return result;
    }
    static bool cmp(const vector<int>& a,const vector<int>& b) {
        if (a[0]==b[0]) return a[1]<b[1];
        return a[0]<b[0];
    }
};
// @lc code=end

