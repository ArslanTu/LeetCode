/*
 * @lc app=leetcode.cn id=2432 lang=cpp
 *
 * [2432] 处理用时最长的那个任务的员工
 */

// @lc code=starthea
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int min=INT_MIN;
        int ans=INT_MAX;
        int start=0;
        for (int i=0;i<logs.size();++i) {
            if (logs[i][1]-start>min) {
                min=logs[i][1]-start;
                ans=logs[i][0];
            } else if (logs[i][1]-start==min) {
                if (logs[i][0]<ans) ans=logs[i][0];
            }
            start=logs[i][1];
        }
        return ans;
    }
};
// @lc code=end

