/*
 * @lc app=leetcode.cn id=1704 lang=cpp
 *
 * [1704] 判断字符串的两半是否相似
 */

// @lc code=start
#include <string>
#include <map>
using std::string;
using std::map;
class Solution {
public:
    bool halvesAreAlike(string s) {
        map<char,int> m;
        string meta="aeiouAEIOU";
        for (auto ch:meta) {
            m[ch]=1;
        }
        int count1=0;
        int count2=0;
        for (int i=0;i<s.size();++i) {
            if (i<s.size()/2&&m[s[i]]==1) ++count1;
            if (i>=s.size()/2&&m[s[i]]==1) ++count2;
        }
        return count1==count2;
    }
};
// @lc code=end

