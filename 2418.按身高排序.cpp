/*
 * @lc app=leetcode.cn id=2418 lang=cpp
 *
 * [2418] 按身高排序
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
using namespace std;
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=names.size();
        map<int,string> mp;
        for (int i=0;i<n;++i) mp[heights[i]]=names[i];
        sort(heights.rbegin(),heights.rend());
        for (int i=0;i<n;++i) names[i]=mp[heights[i]];
        return names;
    }
};
// @lc code=end

