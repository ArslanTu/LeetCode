/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
#include <vector>
#include <algorithm>
using std::sort;
using std::vector;
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>> queue;
        for (int i=0;i<people.size();++i) {
            queue.insert(queue.begin()+people[i][1],people[i]);
        }
        return queue;
    }
    static bool cmp(const vector<int> a,const vector<int> b) {
        if (a[0]==b[0]) return a[1]<b[1];
        return a[0]>b[0];
    }
};
// @lc code=end

