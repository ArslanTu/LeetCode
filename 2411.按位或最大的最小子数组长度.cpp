/*
 * @lc app=leetcode.cn id=2411 lang=cpp
 *
 * [2411] 按位或最大的最小子数组长度
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        vector<int> dp(32,-1);
        for (int i=n-1;i>=0;--i) {
            int maxLen=1;
            for (int j=0;j<32;++j) {
                if ((nums[i]>>j)&1==1) dp[j]=i;
                if (dp[j]!=-1) maxLen=max(maxLen,dp[j]-i+1);
            }
            ans[i]=maxLen;
        }
        return ans;
    }
};
// @lc code=end

