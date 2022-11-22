/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
#include <vector>
#include <string>
using std::vector;
using std::string;
class Solution {
// private:
//     vector<string> permutation;
//     string path;
//     void backtracking(const string&s,int len,int start) {
//         if (path.size()==len) {
//             permutation.push_back(path);
//             return;
//         }
//         for (int i=start;i<=s.size()-(len-path.size())+1;++i) {
//             path.push_back(s[i]);
//             backtracking(s,len,i+1);
//             path.pop_back();
//         }
//     }
public:
    int numDistinct(string s, string t) {
        // permutation.clear();
        // path="";
        // backtracking(s,t.size(),0);
        // int res=0;
        // for (int i=0;i<permutation.size();++i) {
        //     if (permutation[i]==t) ++res;
        // }
        // return res;
        vector<vector<uint64_t>> dp(s.size()+1,vector<uint64_t>(t.size()+1,0));
        dp[0][0]=1;
        for (int i=0;i<=s.size();++i) dp[i][0]=1;
        for (int i=1;i<=s.size();++i) {
            for (int j=1;j<=t.size();++j) {
                if (s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[s.size()][t.size()];
    }
};
// @lc code=end

