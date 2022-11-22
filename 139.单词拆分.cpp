/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_set>
using std::vector;
using std::string;
using std::unordered_set; 

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1,false);
        unordered_set<string> us(wordDict.begin(),wordDict.end());
        dp[0]=true;
        for (int j=1;j<=s.size();++j) {
            for (int i=0;i<j;++i) {
                if (dp[i]&&(us.find(s.substr(i,j-i))!=us.end())) dp[j]=true;
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end

