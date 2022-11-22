/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s=="" || s.size()<2) return s;

        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));

        int maxLen=1;
        int maxStart=0;
        int maxEnd=0;
        for (int r=1;r<s.size();++r) {
            for (int l=0;l<r;++l) {
                if (s[l]==s[r] && (r-l<=2 || dp[l+1][r-1]==true)) {
                    dp[l][r]=true;
                    if (r-l+1>maxLen) {
                        maxLen = r-l+1;
                        maxStart=l;
                        maxEnd=r;
                    }
                }
            }
        }
        return s.substr(maxStart,maxLen);
    }
};
// @lc code=end

