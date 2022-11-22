/*
 * @lc app=leetcode.cn id=2389 lang=cpp
 *
 * [2389] 和有限的最长子序列
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
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        // int capacity=*max_element(queries.begin(),queries.end());
        // int m=queries.size();
        // int n=nums.size();
        // vector<vector<int>> dp(capacity+1,vector<int>(n+1,0));
        // for (int j=1;j<=capacity;++j) {
        //     for (int i=1;i<=n;++i) {
        //         if (j>=nums[i-1]) dp[j][i]=max(dp[j-nums[i-1]][i-1]+1,dp[j][i-1]);
        //         else dp[j][i]=dp[j][i-1];
        //     }
        // }
        // vector<int> ans(m);
        // for (int i=0;i<m;++i) ans[i]=dp[queries[i]][n];
        // return ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> vec(n+1);
        vec[0]=nums[0];
        for (int i=1;i<n;++i) {
            vec[i]=vec[i-1]+nums[i];
        }
        vec[n]=INT_MAX;
        int m=queries.size();
        vector<int> ans(m);
        for (int i=0;i<m;++i) {
            int target=queries[i];
            int left=0,right=n;
            while (left<right) {
                int mid=left+((right-left)>>1);
                if (vec[mid]>target) {
                    right=mid;
                } else left=mid+1;
            }
            ans[i]=left;
        }
        return ans;
    }
};
// @lc code=end

