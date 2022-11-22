/*
 * @lc app=leetcode.cn id=2412 lang=cpp
 *
 * [2412] 完成所有交易的初始最少钱数
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
#include <math.h>
using namespace std;
class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        long long mx=0;
        long long totalLost=0;
        int n=transactions.size();
        for (int i=0;i<n;++i) {
            totalLost+=max(transactions[i][0]-transactions[i][1],0);
            mx=max(mx,(long long)min(transactions[i][0],transactions[i][1]));
        }
        return totalLost+mx;
    }
};
// @lc code=end

