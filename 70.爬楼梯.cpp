/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
#include <math.h>

using std::min;

class Solution {
public:
    //我的思路
    // int climbStairs(int n) {
    //     int count=0;
    //     int numOf_2=n/2;
    //     int i;
    //     for(int j=0;j<=numOf_2;++j){
    //         i = n - j*2;
    //         count += (i==0||j==0)?1:factorial_c((i+j),min(i,j));
    //     }
    //     return count;
    // }
    // long factorial_c(int n, int m){
    //     long fac_c=1;
    //     for(int i=1;i<=m;++i){
    //         fac_c *= n-m+i;
    //         fac_c /= i;
    //     }
    //     return fac_c;
    // }

    //动态规划解法
    int climbStairs(int n) {
        if(n<2) return n;
        int dp[n+1];
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<n+1;++i) dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
    }
};
// @lc code=end