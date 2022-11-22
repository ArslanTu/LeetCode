/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()<=1) return 0;
        int totalProfit=0;
        for (int i = 0;i<prices.size()-1;++i) {
            if (prices[i+1]>prices[i]) totalProfit+=prices[i+1]-prices[i];
        }
        return totalProfit;
    }
};
// @lc code=end

