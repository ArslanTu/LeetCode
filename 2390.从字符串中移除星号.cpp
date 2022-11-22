/*
 * @lc app=leetcode.cn id=2390 lang=cpp
 *
 * [2390] 从字符串中移除星号
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
    string removeStars(string s) {
        string ans="";
        int n=s.size();
        for (int i=0;i<n;++i) {
            if (s[i]!='*') ans+=s[i];
            else ans.pop_back();
        }
        return ans;
    }
};
// @lc code=end

