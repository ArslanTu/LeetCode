/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
#include <vector>
#include <string>
using std::vector;
using std::string;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        // 简单模拟
        if (s=="") return true;
        if (s!=""&&t=="") return false;
        int i=0;
        for (int j=0;j<t.size();++j) {
            if (t[j]==s[i]&&i==s.size()-1) return true;
            else if (t[j]==s[i]) ++i; 
        }
        return false;
    }
};
// @lc code=end

