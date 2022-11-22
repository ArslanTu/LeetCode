/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include <vector>
#include <math.h>

using std::max;
using std::min;
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //贪心算法
        if(prices.size()<2) return 0;
        int maxProfit=0,minPrice=prices[0];
        for(int i=1;i<prices.size();++i){
            maxProfit=max(maxProfit,prices[i]-minPrice);
            minPrice=min(minPrice,prices[i]);
        }
        return maxProfit;
    }
};
// @lc code=end

