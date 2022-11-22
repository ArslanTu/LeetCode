/*
 * @lc app=leetcode.cn id=2430 lang=cpp
 *
 * [2430] 对字母串可执行的最大删除数
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
    int deleteString(string s) {
        int n=s.size();
        vector<vector<int>> lcs(n+1,vector<int>(n+1,0));
        for (int i=n-1;i>=0;--i) {
            for (int j=n-1;j>=0;--j) {
                if (s[i]==s[j]) lcs[i][j]=lcs[i+1][j+1]+1;
            }
        }

        vector<int> dp(n+1,0);
        for (int i=n-1;i>=0;--i) {
            dp[i]=1;
            for (int j=1;i+2*j<=n;++j) {
                if (lcs[i][i+j]>=j) dp[i]=max(dp[i],dp[i+j]+1);
            }
        }
        return dp[0];
    }
};
// @lc code=end

