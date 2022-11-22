/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int j=s.size()-1;
        for (int i=g.size()-1;i>=0&&j>=0;--i) {
            if (g[i]<=s[j]) 
            {
                ++res;
                --j;
            }
        }
        return res;
    }
};
// @lc code=end

